#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define true 1
#define false 0
#define bool unsigned short int

float toFloat(char *);
float sum(Stack *);
float difference(Stack *);
float product(Stack *);
float ratio(Stack *);

int main(){
    Stack s = newStack();

    bool end = false;

    while (!end){
        char n[100];
        printf("a\n");
        scanf("%s", n);

        switch (n[0])
        {
        case '+':
            push(&s,sum(&s));
            break;
        case '-':
            push(&s,difference(&s));
            break;
        case '*':
            push(&s,product(&s));
            break;
        case '/':
            push(&s,ratio(&s));
            break;
        case '$':
            end = true;
            break;
        default:
            push(&s, atof(n));
            break;
        }
        
    }

    printf("%.2f", pop(&s));

    clear(&s);

    return 0;
}

float sum(Stack * s){
    float a,b;
    b = pop(s);
    a = pop(s);
    return a+b;
}
float difference(Stack * s){
    float a,b;
    b = pop(s);
    a = pop(s);
    return a-b;
}
float product(Stack * s){
    float a,b;
    b = pop(s);
    a = pop(s);
    return a*b;
}
float ratio(Stack * s){
    float a,b;
    b = pop(s);
    a = pop(s);
    return a/b;
}