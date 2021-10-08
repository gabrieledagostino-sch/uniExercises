#ifndef __LIST_HEADER__
#define __LIST_HEADER__

typedef struct node
{
    unsigned int val;
    struct node* next;
}Node;

typedef struct list
{
    Node* next;
}List;


void printNodes(List l);
int push_back(List *l, unsigned int val);
int push_top(List *l, unsigned int val);
int removeOccorrence(List *l, unsigned int val);
List newList();

#endif