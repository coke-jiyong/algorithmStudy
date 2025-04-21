#include <stdio.h>
char str[15];
int compare (char * a, char * b) {
    int i =0;
    while(a[i] && b[i]) {
        if (a[i] != b[i])
            return 0;
        i++;
    }
    return a[i] == b[i];
}
int queue[10001];
int main(void) {
    int N ; 
    scanf("%d", &N);
    int idx = 0;
    int head = 0;
    for(int i = 0 ; i < N ; i ++ ) {

        scanf("%s", str);
        if(compare(str,"push")==1){
            int n;
            scanf("%d", &n);
            queue[idx++] = n;
        }
        else if(compare(str,"pop")==1){
            if(head < idx)
                printf("%d\n",queue[head++]);
            else 
                printf("%d\n", -1);
        }
        else if(compare(str,"size")==1){
            printf("%d\n",idx - head);
        }
        else if(compare(str,"empty")==1){
            printf("%d\n", idx - head > 0 ? 0 : 1);
        }
        else if(compare(str,"front")==1){
            if(head < idx) 
                printf("%d\n",queue[head]);
            else
                printf("%d\n",-1);
        }
        else if(compare(str,"back")==1){
            if(head < idx)
                printf("%d\n", queue[idx-1]);
            else
                printf("%d\n", -1);
        }
    }
    return 0;
}