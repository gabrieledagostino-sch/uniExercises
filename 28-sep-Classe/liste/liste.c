#include <stdio.h>
#include <stdlib.h>

#define bool unsigned short int
#define true 1
#define false 0


typedef struct n{
    int val;
    struct  n* next;
    
} Node;

typedef struct list{
    Node* next;
} List;

int push_back(List *s, int el);
int push_front(List *s, int el);
int insert(List *s, int el, int idx);
int orderedInsert(List *s, int el);

int pop_back(List *s, int el);  //TODO
int pop_front(List *s, int el);
int delete(List *s, int idx);   //TODO

bool isEmpty(List *s);

int clear(List *s);

List newList();


int push_back(List *s, int el)
{   
    Node *pred, *elem;

    if(s->next == NULL) return -push_front(s, el);
    pred = s->next;

    while(elem != NULL)
    {
        pred = elem;
        elem = elem->next;
    } 
    elem = (Node*) malloc(sizeof(Node));
    pred->next = elem;
    elem->val = el;
    return 0;
}

int push_front(List *s, int el)
{
    Node* elem =(Node*) malloc(sizeof(Node));

    if(elem == NULL) return 1;

    elem->next = s->next;
    elem->val = el;

    s->next = elem;
    return 0;
}
int insert(List *s, int el, int idx)
{
    Node *elem = s->next;
    int i;
    for (i = 0; i < idx && elem->next != NULL; i++, elem=elem->next);
    if(i != idx) return -1;
    
    Node *newEl = (Node*) malloc(sizeof(Node));
    newEl->next = elem->next;
    elem->next = newEl;
    newEl->val = el;

    return i;
}
int orderedInsert(List *s, int el)
{
    Node *elem = s->next;

    if(elem == NULL) return -push_front(s, el);

    int i = 0;
    while (elem -> next != NULL)
    {
        insert(s, el, i);
        return i;
    }

    push_back(s, el);

}
int pop_back(List *s, int el);  //TODO
int pop_front(List *s, int el)
{
    if(isEmpty(s)) return INT32_MAX;
    
    Node* elem = s->next;
    int val = s->next->val;

    s->next = s->next->next;
    free(elem);

    return val;
}
int delete(List *s, int idx);   //TODO
bool isEmpty(List *s){
    return s->next == NULL;
}
int clear(List *s)
{
    int a = clear(s->next);
    
    if(s -> next == NULL){
        free(s);
        return 0;
    }
    return a;
}
List newList()
{
    List s = {NULL};
    return s;
}
