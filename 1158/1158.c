#include <stdio.h>
int N;
int queue_idx(int n) {
    if(n > N) {
        return 1;
    }
    return n;
}


int seq[5001];
int main(void) {
    int K;
    scanf("%d %d", &N,&K);
    for(int i = 1 ; i <= N ; i ++)
        seq[i]= i;
    
    int died = 0;
    int pointer = 0;
    printf("<");
    while(died < N) {
        int cnt = 0;
        while (cnt < K) {
            if(seq[queue_idx(pointer+1)] != -1)
                cnt ++;
            pointer = queue_idx(pointer+1);
        }
        if(died == N-1) 
            printf("%d",seq[pointer]);
        else
            printf("%d, ",seq[pointer]);
        seq[pointer] = -1;
        died ++;
    }
    printf(">\n");
}
