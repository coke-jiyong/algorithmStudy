#include <stdio.h>
#include <stdlib.h>
int N;
typedef struct node {
    int n;
    struct node* next;
} NODE;

NODE * queue;
NODE * tail;

int pop(){
    int n = queue->n;
    NODE * tmp = queue->next;
    free(queue);
    queue=NULL;
    queue = tmp;
    return n;
}

void push_back(int data) {
    NODE * new = (NODE*)malloc(sizeof(NODE));
    if(new == NULL) abort();

    if(queue == NULL) {
        queue = new;
        queue->n = data;
        queue->next = NULL;
    } else {    
        if(tail == NULL) {
            new->n = data;
            new->next = queue;
            tail = new;
            queue->next = tail;
        } else {
            new->n = data;
            new->next = queue;
            tail->next = new;
            tail = new;
        }
    }
}

void clear() {
    while(1) {
        if (queue == tail) {
            free(tail);
            return;
        }
        NODE* tmp = queue->next;
        if(queue){
            free(queue);
            queue = NULL;
        }
        queue = tmp ;
    }
}

void print() {
    NODE * tmp = queue;
    printf("<");
    while(tmp != tail) {
        printf("%d ", tmp->n);
        tmp = tmp->next;
    }
    printf("%d>\n",tail->n);
}

int size() {
    int n = 0 ;
    NODE * tmp = queue;
    while(tmp != tail) {
        n++;
        tmp = tmp->next;
    }
    return ++n;
}

int main(void) {
    int K;
    scanf("%d %d", &N,&K);
    NODE * queue;
    for(int i = 1 ; i <= N ; i ++)
        push_back(i);
    printf("<");
    while(size() > 1) {
        for(int i = 0 ; i < K-1; i ++) 
            push_back(pop());
        printf("%d, ",pop());
    }
    printf("%d>\n", pop());
}
