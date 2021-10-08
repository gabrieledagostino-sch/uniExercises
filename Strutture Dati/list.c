#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//unnecessary stuff, i just find it better to write like this (might consider doing it with an enum)
#define bool unsigned short int
#define true 1
#define false 0

//ERROR IN CASE I CAN'T ALLOCATE MEMORY
#define LS_MEMERR -1
//ERROR IN CASE I TRY TO GO IN A NON INITIALIZED MEMORY LOCATION
#define LS_OOBERR -2
//THERE WAS NO ERROR -> the function worked correctly
#define LS_NO_ERR 0
//DIDN'T SET AN EQUALS FUNCTION BUT TRYING TO USE A FUNCTION THAT REQUIRES IT 
#define LS_NO_EQ  -3


//#define DEBUG                             //used it for debugging the fcode

//a better way to call void pointers
typedef void* ls_Element;

//a wrapper for elments in the list
typedef struct Node
{
    struct Node* next;  //pointer to the next wrapper
    ls_Element value;   //the element value
} ls_Node;

//the List itself, always save this
typedef struct List
{
    ls_Node* next;      //the pointer to the head
    size_t dataSize;    //the size of the data insisde the elements
    bool (*equals) (void*, void*);  //a function that defines a way to say if 2 ls_Elements are equals, should return 0 for false
} ls_List;

//Insert operations
int     ls_pushBack     (ls_List *l, const ls_Element val);                         //inserts val at the end of the list, to put val you've to get it's pointer 
int     ls_pushFront    (ls_List *l, const ls_Element val);                         //inserts val at the beginning of the list
int     ls_insert       (ls_List *l, const ls_Element val, size_t idx);             //inserts val at the specified index

//Remove operations 
int     ls_popBack      (ls_List *l);                                               //remove the last ls_element of the list
int     ls_popFront     (ls_List *l);                                               //remove the first ls_element of the list
int     ls_removeAt     (ls_List *l, size_t idx);                                   //remove the ls_element at the idx position

//Utility operations    
int     ls_clear        (ls_List *l);                                               //clears the list and deallocates all the memory used
bool    ls_isEmpty      (ls_List l);                                                //returns one if the list is empty, 0 otherwise
size_t  ls_length       (ls_List l);                                                //returns the length of the list

//List constructor
ls_List ls_newList(size_t size, bool (*equals)(void*, void*));

//Insert operations - NodeWise
int     pushBack        (ls_Node *l, const ls_Element val, size_t dataSize);
int     insert          (ls_Node *l, const ls_Element val, size_t idx, size_t dataSize);

//Remove operations - NodeWise
int     popBack         (ls_Node * l);
int     removeAt        (ls_Node * l, size_t idx);

//Utility operations - NodeWise
int     clear           (ls_Node *l);
size_t  length          (const ls_Node *l);
int     freeNode        (ls_Node *l);

//NewNode Constructor
ls_Node* newNode        (const ls_Element val, size_t size);

//General list operations
int     ls_find         (ls_List l,       const ls_Element val);                    //returns the position of the ls_element val
ls_Element ls_getAt     (ls_List l,       size_t idx);                              //returns the pointer to the ls_element at the position idx
int     ls_setAt        (ls_List *l,      size_t idx,        const ls_Element val); //changes the value of the idx-th ls_element to val
int     ls_removeEl     (ls_List *l,      const ls_Element val);                    //removes the first occurrence of the ls_element val
int     ls_countOcc     (ls_List l,       const ls_Element val);                    //returns the number of occurrence of the ls_element val

//General list operations - NodeWise
int     find            (const ls_Node *l, const ls_Element val, bool (*equals)(void*, void*), size_t idx);
ls_Element getAt           (const ls_Node *l, size_t idx);
int     setAt           (ls_Node *l,       size_t idx,        const ls_Element val,            size_t dataSize);
int     countOcc        (const ls_Node *l, const ls_Element val, bool (*equals)(void*, void*));






/***********************************************************************************************************************************************************
 *
 *  List operations
 *
 ***********************************************************************************************************************************************************/



/*************************************************
 * 
 * Inserts Operations
 * 
*************************************************/
//INSERT A THE HEAD DEFINITION
int     ls_pushFront    (ls_List *l, const ls_Element val)
{
    ls_Node *newEl      =   newNode(val, l->dataSize);
    if(newEl == NULL)   return LS_MEMERR;

    newEl -> next       =   l -> next;                                              //the next node of the new is the old list head
    l->next             =   newEl;                                                  //the next node of the list is the new ls_element
    
    return LS_NO_ERR;
}

//INSERTS AT THE TAIL
int     ls_pushBack     (ls_List *l, const ls_Element val)
{
    if(l->next == NULL) return ls_pushFront(l, val);

    return pushBack(l->next, val, l->dataSize);
}

//INSERTS AT THE POSITION INDICATED
int     ls_insert       (ls_List *l, const ls_Element val, size_t idx)
{
    if(idx == 0)            return ls_pushFront(l, val);
    if(l->next == NULL)     return LS_OOBERR;


    return insert(l->next, val, idx-1, l->dataSize);
}




/*************************************************
 * 
 * Remove Operations
 * 
*************************************************/

//REMOVES THE HEAD ls_ELEMENT
int     ls_popFront     (ls_List *l)
{
    if (l->next == NULL) return LS_OOBERR;
    
    ls_Node * oldNode = l->next;
    
    l->next = oldNode -> next;

    freeNode(oldNode);

    return LS_NO_ERR;
}

//REMOVES THE TAIL ls_ELEMENT
int     ls_popBack      (ls_List *l)
{
    if (l->next == NULL)        return LS_OOBERR;
    if (l->next->next == NULL)  return ls_popFront(l);                              //I actually check the next next, so that i can set null to the value of the current node

    return popBack (l->next);
}

//REMOVES THE IDX-th ls_ELEMENT
int     ls_removeAt     (ls_List *l, size_t idx)
{
    if (idx == 0)        return ls_popFront(l);                                     //asked to remove the first node
    if (l->next == NULL) return LS_OOBERR;                                          //tried to remove in an empty list

    return removeAt(l->next, idx);
}



/*************************************************
 * 
 * Utilities
 * 
*************************************************/
//LIST CONSTRUCTOR DEFINITION
ls_List     ls_newList      (size_t size, bool (*equals)(void*, void*))
{
    ls_List     l;

    l.next      =   NULL;
    l.dataSize  =   size;                                                           //this is the byte size of the ls_elements :)
    l.equals    =   equals;                                                         //this is the equals function, for stuff like find etc.

    return  l;
}

//FREE ALL THE ALLOCATED MEMORY FROM THE LIST
int     ls_clear        (ls_List *l)
{
    if(l -> next != NULL) clear(l->next);

    l->next = NULL;

    return LS_NO_ERR;
}

//SAYS IF THE LIST IS EMPTY
bool    ls_isEmpty      (ls_List l)
{
    return l.next == NULL;
}

//RETURNS THE LENGTH OF THE LIST (NUMBER OF ls_ELEMENTS)
size_t  ls_length       (ls_List l)
{
    if  (l.next == NULL) return 0;

    return length(l.next);
}




/*************************************************
 * 
 * General list operations
 * 
*************************************************/

//returns the position of the ls_element val
int     ls_find         (ls_List l, const ls_Element val)
{
    if (l.equals == NULL)   return LS_NO_EQ;
    if (l.next == NULL)     return LS_OOBERR;

    return find(l.next, val, l.equals, 0); 
}

//returns the pointer to the ls_element at the position idx
ls_Element ls_getAt        (ls_List l, size_t idx)
{
    if (l.next == NULL) return NULL;

    return getAt(l.next, idx);
}

//changes the value of the idx-th ls_element to val
int     ls_setAt        (ls_List *l,      size_t idx,        const ls_Element val)
{
    if (l->next == NULL) return LS_NO_ERR;

    return setAt(l->next, idx, val, l->dataSize);
}

//removes the first occurrence of the ls_element val
int     ls_removeEl     (ls_List *l,      const ls_Element val)
{
    if (l->equals == NULL)  return LS_NO_EQ;
    if (l->next == NULL)    return LS_OOBERR;

    removeAt(l->next, ls_find(*l, val));
}

//returns the number of occurrence of the ls_element val
int     ls_countOcc     (ls_List l, const ls_Element val)
{
    if (l.equals == NULL) return LS_NO_EQ;
    if (l.next == NULL) return 0;

    return countOcc(l.next, val, l.equals);
}                






/***********************************************************************************************************************************************************
 *
 *  Node operations
 *
 ***********************************************************************************************************************************************************/



/*************************************************
 * 
 * Inserts Operations
 * 
*************************************************/

//PUSHBACK NODEWISE
int     pushBack        (ls_Node *l, const ls_Element val, size_t dataSize)
{
    if (l->next == NULL)
    {
        ls_Node *newEl      = newNode(val, dataSize);                               //create a new Node
        if (newEl == NULL)  return LS_MEMERR;                                      //couldn't allocate the node
        
        newEl -> next       = NULL;                                                 //the next node of the ls_element will become NULL (it's the tail)
        l -> next           = newEl;                                                //the next node of the previous tail is the new tail
        
        return LS_NO_ERR; 
    }

    return pushBack(l->next, val, dataSize);                                        //continue the recursion (still not in the tail)
}

//INSERT NODEWIDE
int     insert          (ls_Node *l, const ls_Element val, size_t idx, size_t dataSize)
{
    if (idx == 0)
    {
        ls_Node* newEl = newNode(val, dataSize);
        if (newEl == NULL)  return LS_MEMERR;                                       //couldn't allocate the node
        newEl -> next  = l->next;
        l->next = newEl;
        return LS_NO_ERR;
    }
    if (l->next == NULL) return LS_OOBERR;                                          //Tried to insert in an undefined position (out of bounds)

    return insert(l->next, val, idx-1, dataSize);
}




/*************************************************
 * 
 * Remove Operations
 * 
*************************************************/

//popBack
int     popBack         (ls_Node * l)
{
    if(l->next->next == NULL)                                                       //actually pops
    {
        freeNode(l->next);
        l->next = NULL;
        return LS_NO_ERR;
    }


    return popBack(l->next);
}

//REMOVES THE IDX-TH ls_ELEMENT - NODEWISE
int     removeAt        (ls_Node * l, size_t idx)
{
    if(l->next == NULL) return LS_OOBERR;                                           //Tried to remove a nonexistent node
    if(idx == 1)                                                                    //Need to remove the next
    {
        ls_Node* removed = l->next;

        l->next = removed->next;

        freeNode (removed);

        return LS_NO_ERR;
    }

    return removeAt(l->next, idx-1);
}




/*************************************************
 * 
 * Utilities
 * 
*************************************************/

//NODE CONSTRUCTOR DEFINITION
ls_Node*    newNode         (const ls_Element val, size_t size)
{
    ls_Node *newEl      = (ls_Node*) malloc(sizeof(ls_Node));                       //Create the new node

    if(newEl == NULL)   return NULL;                                                //malloc didn't allocate the node

    newEl -> value      = malloc(sizeof(size));                                     //allocate the value

    if(newEl -> value == NULL)                                                      //malloc didn't allocate the value
    {   
        free(newEl);    
        return NULL;    
    }   

    memcpy(newEl->value, val, size);                                                //copy the value 

    return newEl;   

}   

//FREES THE ALLOCATED MEMORY OF THE NODE    
int     freeNode        (ls_Node *l)    
{   
    if (l->value != NULL)   free(l->value);                                         //need to free l->value too since it was allocated with malloc

    free(l);    

    return LS_NO_ERR;   
}   

//CLEAR THE LIST NODE-WISE  
int     clear           (ls_Node *l)    
{   
    if(l->next != NULL) clear(l->next);                                             //i've nodes in front of me

    freeNode(l);

    return LS_NO_ERR;
}

//RETURNS THE LENGTH OF THE LIST STARTING FROM THE NODE
size_t  length          (const ls_Node *l)
{
    if(l->next == NULL) return 1;

    return 1 + length(l->next);
}




/*************************************************
 * 
 * Utilities
 * 
*************************************************/

int     find            (const ls_Node *l, const ls_Element val, bool (*equals)(void*, void*), size_t idx)
{
    if((*equals)(val, l->value)) return idx;
    if(l->next == NULL)          return LS_OOBERR;

    return find(l->next, val, equals, idx+1);
}

ls_Element getAt           (const ls_Node *l, size_t idx)
{
    if (idx == 0)        return l->value;
    if (l->next == NULL) return NULL;

    return getAt(l->next, idx-1);
}

int     setAt           (ls_Node *l,       size_t idx,        const ls_Element val,            size_t dataSize)
{
    if (idx == 0)
    {
        memcpy(l->value, val, dataSize);
        return LS_NO_ERR;
    }
    if (l->next == NULL) return LS_OOBERR;

    return setAt(l->next, idx-1, val, dataSize);
}

int     countOcc        (const ls_Node *l, const ls_Element val, bool (*equals)(void*, void*))
{
    if(l->next == NULL) return (*equals)(val, l->value);

    return (*equals)(val, l->value) + countOcc(l->next, val, equals);
}












#ifdef DEBUG

void print(const ls_Node *l)
{
    printf("%d -> ", *((int*)l->value));
    if(l->next == NULL)
    {
        printf("||\n");
        return;
    }
    print(l->next);
}

void ls_print(const ls_List l)
{
    if(l.next == NULL)
    {
        printf("-||");
        return;
    }
    print(l.next);
}

bool intEquals(void* a, void* b)
{
    return *((int *)a) == *((int *)b);
}

int main()                  
{
    ls_List l = ls_newList(sizeof(int), &intEquals);
    ls_List emptyList = ls_newList(sizeof(int), &intEquals);

    int a = 0;
    ls_pushFront(&l, (ls_Element)&a);
    a = 1;
    ls_pushFront(&l, (ls_Element)&a);
    a = 2;
    ls_pushFront(&l, (ls_Element)&a);
    ls_print(l);
    
    ls_popFront(&l);
    ls_print(l);

    a = 3;
    ls_pushBack(&l, (ls_Element)&a);
    a = 4;
    ls_pushBack(&l, (ls_Element)&a);
    ls_print(l);

    a = 5;
    int r = ls_insert(&l, (ls_Element)&a, 3);
    ls_print(l);
    printf("%d\n", r);

    r = ls_popFront(&emptyList);
    printf("%d\n", r);
    r = ls_popBack(&emptyList);
    printf("%d\n", r);
    
    ls_removeAt(&l, 1);
    ls_print(l);
    
    printf("%hu\n", ls_isEmpty(l));
    printf("%hu\n", ls_isEmpty(emptyList));

    printf("%u\n", ls_length(l));

    a = 0;
    ls_setAt(&l, 1, (ls_Element)&a);
    ls_print(l);

    a = 4;
    int f = ls_find(l, (ls_Element)&a);
    printf("%d\n", f);
    a = 3;
    f = ls_find(l, (ls_Element)&a);
    printf("%d\n", f);

    void* ptr = (ls_getAt(l, 2));
    int * iptr= (int*) ptr;
    a = *iptr;
    printf("%d\n", a);
    
    f = ls_find(l, (ls_Element)&a);
    printf("%d\n", f);

    ls_removeEl(&l, (ls_Element) &a);
    ls_print(l);

    printf("%u\n", ls_countOcc(l, &a));
    a = 0;
    printf("%u\n", ls_countOcc(l, &a));
    
    
    return LS_NO_ERR;
}
#endif