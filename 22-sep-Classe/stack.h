#ifndef STACK_HEADER
#define STACK_HEADER

typedef struct Stack
{
    struct Stack *next;
    float val;
    unsigned short int head;

} Stack;

int push(Stack*, float);
float pop(Stack*);

float top(Stack);
unsigned short int empty(Stack);

void printStack(Stack*);

#endif
