#include <stdio.h>
char str[15];
#define MAX  20002
int compare (char * a, char * b) {
    int i =0;
    while(a[i] && b[i]) {
        if (a[i] != b[i])
            return 0;
        i++;
    }
    return a[i] == b[i];
}
int Deque[MAX];
int main(void) {
    int N ; 
    scanf("%d", &N);
    int idx = 0;
    int head = MAX/2;
    int tail = MAX/2;
    for(int i = 0 ; i < N ; i ++ ) {

        scanf("%s", str);
        if(compare(str,"push_front")==1){
            int n;
            scanf("%d", &n);
            Deque[--head] = n;
        }else if(compare(str,"push_back")==1){
            int n;
            scanf("%d", &n);
            Deque[tail++] = n;
        }
        else if(compare(str,"pop_front")==1){
            if(head == tail)
                printf("%d\n", -1);
            else
                printf("%d\n",Deque[head++]);
        }else if(compare(str,"pop_back")==1){
            if(head == tail)
                printf("%d\n", -1);
            else {
                printf("%d\n",Deque[tail-1]);
                tail --;
            }   
        }
        else if(compare(str,"size")==1){
            if(head >= tail)
                printf("%d\n",0);
            else
                printf("%d\n",tail - head);
        }
        else if(compare(str,"empty")==1){
            printf("%d\n", head >= tail ? 1 : 0);
        }
        else if(compare(str,"front")==1){
            if(head >= tail)
                printf("%d\n",-1);
            else
                printf("%d\n", Deque[head]);
        }
        else if(compare(str,"back")==1){
            if(head >= tail)
                printf("%d\n",-1);
            else
                printf("%d\n", Deque[tail-1]);
        }
    }
    return 0;
}