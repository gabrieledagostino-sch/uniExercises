#ifndef STACK_HEADER
#define STACK_HEADER

typedef struct Stack
{
    struct Stack *next;
    float val;
    unsigned short int head;

} Stack;

Stack newStack();

int push(Stack*, float);
float pop(Stack*);

int clear(Stack* );

float top(Stack);
unsigned short int empty(Stack);

void printStack(Stack*);

#endif
