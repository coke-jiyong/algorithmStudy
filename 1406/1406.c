#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char data;
    struct node * next;
    struct node * prev;
} NODE;
NODE * head;
NODE * cursor;
NODE * tail;


void print(){
    NODE *tmp = head->next;
    while(tmp != tail) {
        printf("%c", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void init() {
    head = (NODE*)malloc(sizeof(NODE));
    tail = (NODE*)malloc(sizeof(NODE));
    if (head == NULL || tail == NULL)
        abort();
    head->prev= NULL;
    head->next= tail;
    tail->prev= head;
    tail->next= NULL;
}

void new_node(char c) {
    NODE * tmp = (NODE*)malloc(sizeof(NODE));
    if(tmp == NULL)
        abort();
    tmp->data = c;
    if(head->next==tail) {
        tmp->prev = head;
        tmp->next = tail;
        head->next = tmp;
        tail->prev = tmp;
        cursor = tmp;
    } else {
        tmp->prev=cursor;
        tmp->next=tail;
        cursor->next=tmp;
        tail->prev=tmp;
        cursor = tmp;
    }
}

void move_right() {
    if (cursor->next != tail)
        cursor=cursor->next;
    //printf("cursor: %c\n", cursor->data);
}

void move_left() {
    if (cursor->prev != NULL)
        cursor=cursor->prev;
    //printf("cursor: %c\n", cursor->data);
}

void del() {
    if(cursor != head) {
        NODE * tmp = cursor;
        cursor->prev->next = cursor->next;
        cursor->next->prev = cursor->prev;
        cursor = cursor->prev;
        free(tmp);
    }
    //print();
}

void add_left_of_cursor(char c){
    NODE * new = (NODE*)malloc(sizeof(NODE));
    if(new == NULL)
        abort();
    new->data = c;
    if(cursor == head) {
        new->prev = head;
        new->next = head->next;
        head->next->prev = new;
        head->next = new;
        cursor = new;
    } else {
        new->prev = cursor;
        new->next = cursor->next;
        cursor->next->prev = new;
        cursor->next = new;
        cursor = new;
    }
    //print();
}
void clear() {
    while (head != NULL) {
        NODE * tmp = head;
        head = head->next;
        free(tmp);
    }
}
int main(void) {
    init ();
    char c;
    while((c = getchar()) != '\n') { 
        new_node(c);
    }
    
    int n;
    scanf(" %d", &n);
    for(int i = 0 ; i < n ; i ++) {
        char c;
        scanf(" %c", &c);
        if(c=='L') {
            move_left();    
        }
        else if (c=='D'){
            move_right();
        }
        else if(c=='B'){
            del();
        }
        else if(c == 'P') {
            char d ;
            scanf(" %c", &d);
            add_left_of_cursor(d);
        }
    }
    print();
    clear();
    return 0 ;
}