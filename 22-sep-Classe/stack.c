#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>

typedef struct Stack
{
    struct Stack *next;
    float val;
    unsigned short int head;

} Stack;

int push(Stack* , float);
float pop(Stack* );

float top(Stack);
unsigned short int empty(Stack);
void printStack(Stack* );

int push(Stack *s, float a){
    if(s->head == 0) return -1;
    
    Stack* newEl = (Stack*)malloc(sizeof(Stack));
    newEl->head = 0;
    newEl->next = s->next;
    newEl->val = a;

    s->next = newEl;
    
    return 1;
}
float pop(Stack *s){
    if(s->head == 0) return -1;
    if(s->next == NULL) return -1;

    Stack *popped = s->next;
    float val = popped->val;

    s->next = popped->next;
    free(popped);

    return val;
}

float top(Stack s){
    if(s.head == 0) return -1;
    return s.next->val;
}

unsigned short int empty(Stack s){
    return s.next == 0;
}

void printStack(Stack* s){
    printf("%f->", s->val);
    if(s->next == NULL)
    {
        printf("|\n");
        return;
    }

    printStack(s->next);
}