/**
 * 
 * Implementare una coda (struttura di dati che funziona con il principio FIFO), utilizzando liste concatenate. 
 * Scrivere un programma che offre un menu per utilizzare la coda, con la struttura:
 * 0: Crea una nuova coda vuota (cancellando eventualmente gli elementi esistenti)
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    struct Node* next;
    int n;
} Node;

typedef Node* Queue;

int new(Queue *x);
int push(Queue *x);
int pop(Queue *x);
int peek(Queue *x);
int print(Queue *x);

int (*menu[5])(Queue*) = {new, push, pop, peek, print};

int main(int argc, char** argv)
{
    int op;
    Queue q = NULL;
    while(1)
    {
        scanf("%p", &op);
        int n = menu[op](&q);
        printf("%d\n", n);
    }
    return 0;
}

int new(Queue *x)
{
    if(*x == NULL) return 0;
    new(&(*x)->next);
    free(*x);
    *x = NULL;
    return 0;
}

int push(Queue *x)
{
    int n;
    scanf("%d", &n);
    Queue newEl = malloc(sizeof(Node));
    newEl->next = (*x);
    newEl->n = n;
    *x = newEl;
    return 0;
}

int pop(Queue *x)
{
    if((*x) == NULL) return -1;
    if((*x)->next == NULL)
    {
        int n = (*x)->n;
        free(*x);
        *x = NULL;
        return n;
    }
    return pop(&(*x)->next);
}

int peek(Queue *x)
{
    if(*x == NULL) return -1;
    if((*x)->next == NULL) return (*x)->n;
    return peek(&(*x)->next);
}

int print(Queue *x)
{
    if(*x == NULL){
        printf("NULL\n");
        return 0;
    }
    printf("%d -> ", (*x)->n);
    return print(&(*x)->next);
}