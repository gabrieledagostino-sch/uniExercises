#include <stdlib.h>
#include <stdio.h>
//#define debug

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
int clear(List *a);

List* listUnion(List a, List b);

unsigned int compare(unsigned int a, unsigned int b);

int ordIn(Node *l, unsigned int val);
void print(Node *l);
int cl(Node *b);


List newList()
{
    List l = {NULL};
    return l;
}

int orderedInsert(List *l, unsigned int val)
{
    if(l == NULL) return -1;
    if(l->next == NULL || !compare(l->next->val, val))
    {
        Node * new = (Node *) malloc(sizeof(Node));
        new->val = val;
        new->next = l->next;
        l->next = new;
        return 0;
    }
    return ordIn(l->next, val);
}

void printList(List l)
{
    print(l.next);
}

void print(Node* l)
{
    if(l == NULL)   return;
    printf("%d\n", l->val);
    print(l -> next);
}
int ordIn(Node *l, unsigned int val)
{
    if(l->next == NULL || !compare(l->next->val, val))
    {
        Node * new = (Node *) malloc(sizeof(Node));
        new->val = val;
        new->next = l->next;
        l->next = new;
        return 0;
    }
    return ordIn(l->next, val);
    
}

unsigned int compare(unsigned int a, unsigned int b)
{
    //if a > b >> b-a < 0
    //if a == b >> b-a = 0
    //if b > a >> b-a > 0
    return a<=b;
}

List* listConcatenation(List a, List b)
{
    List* c =(List*) malloc(sizeof(List));
    c->next = NULL;

    Node *an, *bn;
    an = a.next, bn = b.next;
    
    if(an == NULL && bn == NULL)    return c;            //Both lists are empty

    Node *cn = (Node*) malloc(sizeof(Node));
    c->next = cn;

    while(an != NULL && bn != NULL)                    //Copy until one of the lists is empty
    {
        if(compare(an->val, bn->val)) // a <= b
        {
            cn->val = an->val;
            an = an->next; 
        }else{ //b < a
            cn->val = bn->val;
            bn = bn->next;
        }

        cn->next = (Node*) malloc(sizeof(Node));
        cn = cn->next;
        cn->next = NULL;
    }

    if (an == NULL) an = bn;                        //if an is null it means it's the first that finished
    
    while(an != NULL)                               //continue to copy the list that isn't empty
    {
        cn->val = an->val;
        cn->next = (Node*) malloc(sizeof(Node));
        cn = cn->next;
        cn->next = NULL;
        an = an->next;
    }

    cn = c->next;
    while(cn->next->next != NULL) cn = cn->next;
    free(cn->next);
    cn->next = NULL;
    
    return c;
}

int clear(List *a)
{
    if(a->next == NULL) return -1;
    int v = cl(a->next);
    free(a);
    a = NULL;
    return v;
}
int cl(Node *b)
{
    if(b == NULL) return 0;
    int v = cl(b->next);
    free(b);
    return v;
}

List *listIntersect(List a, List b)
{
    List *conc = listConcatenation(a,b);

    if(conc->next == NULL) return conc;             //both lists are empty
    #ifdef debug
        printList(*conc);
    #endif

    List *c = (List*) malloc(sizeof(List));
    Node *v = conc->next;
    
    int prev = -5;
    while(v != NULL)
    {
        if(v->val == prev) orderedInsert(c, prev);
        prev = v->val;
        do{
            v = v->next;
        }while (v->val == prev);
    }
    clear(conc);
    return c;

}               