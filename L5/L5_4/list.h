#ifndef __LIST_HEADER__
#define __LIST_HEADER__

typedef struct node
{
    struct node *next;
    unsigned int val;
} Node;

typedef struct list
{
    Node* next;
}List;

int orderedInsert(List *l, unsigned int val);
void printList(List l);
List newList();

List* listConcatenation(List a, List b);
List *listIntersect(List a, List b);

#endif