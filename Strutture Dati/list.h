#ifndef __LS_HEADER__
#define __LS_HEADER__

//ERROR IN CASE I CAN'T ALLOCATE MEMORY
#define LS_MEMERR -1
//ERROR IN CASE I TRY TO GO IN A NON INITIALIZED MEMORY LOCATION
#define LS_OOBERR -2
//THERE WAS NO ERROR -> the function worked correctly
#define LS_NO_ERR 0
//DIDN'T SET AN EQUALS FUNCTION BUT TRYING TO USE A FUNCTION THAT REQUIRES IT 
#define LS_NO_EQ  -3



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

#endif