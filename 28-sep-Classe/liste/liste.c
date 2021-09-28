#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int val;
    struct  n* next;
    
} Node;

typedef struct list{
    Node* next;
} List;