/********************************
*                               *
*   A Library for a stack       *
*       Data structure          *
*   it's a dynamic structure    *
*                               *
********************************/
#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>
#define bool unsigned short int
#define true 1
#define false 0
//Stack
/*
    next : pointer to the next stack element
    val  : what the stack is holding
    head : a flag, if the flag is true(1) it is treated as a pointer to the rest of the stack, otherwise it is a normal element
    // it is suggested to save the head and to create a stack call the newStack() function
*/
typedef struct Stack
{
    struct Stack *next;
    float val;
    bool head;

} Stack;

Stack newStack();


int push(Stack* , float);   //puts the element after the head of the stack
float pop(Stack* );         //deletes the element after the head of the stack

float top(Stack);           //returns the elemenet that is after the stack
bool empty(Stack);    //return 1 if the stack is only composed by the head 0 otherwise
void printStack(Stack* );   //prints the stack via printf the format is val->next.val->...->||

int clear(Stack *);
int clearStack(Stack *);

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

bool empty(Stack s){
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

int clear(Stack *s){
    int a = 0;
    
    if(s->next == NULL){
        return 0;
    }
    if(s->head == true){
        clearStack(s->next);
    }
    return a;
}

int clearStack(Stack *s){

    int a = clear(s->next);
    
    if(s -> next == NULL){
        free(s);
        return 0;
    }
    return a;
}

Stack newStack(){
    Stack s;
    s.next  = NULL;
    s.head  = true;
    s.val   = 0;
    return s;
}