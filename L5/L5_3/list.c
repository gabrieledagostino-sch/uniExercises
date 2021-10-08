#include <stdlib.h>
#include <stdio.h>

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

void print(Node* l);
int pushb(Node *l, unsigned int val);
int rem(Node *l, unsigned int val);

List newList(){
    List l = {NULL};
    return l;
}




void printNodes(List l)
{
    print(l.next);
}

int push_back(List *l, unsigned int val)
{
    if(l == NULL) return -1;
    if(l->next == NULL) return push_top(l, val);
    return pushb(l->next, val);
}

int push_top(List *l, unsigned int val)
{   
    if(l == NULL) return -1;
    Node* new = (Node*) malloc(sizeof(Node));
    new->next = l->next;
    l->next = new;
    new->val = val;
    return 0;
}

int removeOccorrence(List *l, unsigned int a)
{
    if(l == NULL) return -1;
    if(l->next == NULL) return -1;
    if(l->next->val == a)
    {
        Node *popped = l->next;
        l->next = popped->next;
        free(popped);
        return 0;
    }
    return rem(l->next, a);
}



void print(Node* l)
{
    if(l == NULL)   return;
    printf("%d\n", l->val);
    print(l -> next);
}

int pushb(Node *l, unsigned int val)
{
    if(l->next != NULL) return pushb(l->next, val);
    Node* new = (Node*) malloc(sizeof(Node));
    new->val = val;
    new->next = NULL;
    l->next = new;
    return 0;
}

int rem(Node *l, unsigned int val)
{
    if(l->next == NULL) return -1;
    if(l->next->val == val)
    {
        Node* popped = l->next;
        l->next = popped->next;
        free(popped);
        return 0;
    }
    return rem(l->next, val);
}

