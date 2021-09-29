#ifndef LIST_HEADER
#define LIST_HEADER

typedef struct n{
    int val;
    struct  n* next;
    
} Node;

typedef struct list{
    Node* next;
} List;

int push_back(List s, int el);
int push_front(List s, int el);
int insert(List s, int el, int idx);


int pop_back(List s, int el);
int pop_front(List s, int el);
int remove(List s, int idx);

unsigned short int isEmpty(List s);

int clear(List s);

List newList();

#endif