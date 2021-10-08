#include <stdlib.h>
#include <string.h>
#define bool unsigned short int
#define true 1
#define false 0

typedef void* Element;

typedef struct Node
{
    struct Node* next;
    Element value;
} ls_Node;

typedef struct List
{
    ls_Node* next;
    size_t dataSize;
} ls_List;

int ls_pushBack(ls_List *l, const void* val);
int ls_pushFront(ls_List *l, const void* val);
int ls_insert(ls_List *l, size_t idx);


int ls_popBack(ls_List *l);
int ls_popFront(ls_List *l);
int ls_removeAt(ls_List *l, size_t idx);

int ls_clear(ls_List *l);
bool ls_isEmpty(ls_List *l);
unsigned int ls_length(ls_List *l);

int pushBack(ls_Node *l, void* val, size_t dataSize);
int insert(ls_Node *l, size_t idx, size_t dataSize);

ls_List ls_newList(size_t size);

int popBack(ls_Node * l);
int removeAt(ls_Node * l, size_t idx);

int clear(ls_Node *l);
unsigned int length(ls_Node *l);

ls_Node* newNode(const void* val, const size_t size);

ls_List ls_newList(size_t size)
{
    ls_List l;

    l.next = NULL;
    l.dataSize = size;

    return  l;
}

int ls_pushBack(ls_List *l, const void* val)
{
    if(l -> next == NULL) return -1;

    return pushBack(l->next, val, l->dataSize);
}
int ls_pushFront(ls_List *l, const void* val)
{
    ls_Node *newEl  = (ls_Node*) malloc(sizeof(ls_Node));   //Create the new node
    newEl -> value  = malloc(sizeof(l->dataSize));          //in the value put a pointer of the size of the element
    
    if(newEl -> value == NULL) return -1;                   //malloc had an allocation error
    
    newEl -> next   = l -> next;                            //the next node of the new is the old list head
    l->next         = newEl;                                //the next node of the list is the new element
    
    memcpy(newEl->next, val, l->dataSize);
    
    return 0;
}
int ls_insert(ls_List *l, size_t idx);

ls_Node* newNode(const void* val, const size_t size)
{
    ls_Node *newEl  = (ls_Node*) malloc(sizeof(ls_Node));   //Create the new node
    
    if(newEl == NULL) return NULL;                          //malloc didn't allocate the node
    
    newEl -> value  = malloc(sizeof(size));                 //allocate the value

    if(newEl -> value == NULL)                              //malloc didn't allocate the value
    {
        free(newEl);
        return NULL;
    }

    memcpy(newEl->value, val, size);                        //copy the value 

    return newEl;

}
