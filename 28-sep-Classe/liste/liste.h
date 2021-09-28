#ifndef LIST_HEADER
#define LIST_HEADER

typedef struct n{
    int val;
    struct  n* next;
    
} Node;

typedef struct list{
    Node* next;
} List;

#endif