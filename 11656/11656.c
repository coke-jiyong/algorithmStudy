#include <stdio.h>
#include <string.h>

char arr[1001][1001];
int arrIdx = 0;


int main(void) {
    char str[1001];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i ++) {
        sprintf(arr[arrIdx++] , "%s", str+i);
    }
    for(int i = 0 ; i < arrIdx ; i ++) {
        for(int j = i + 1 ; j < arrIdx ; j ++) {
            if(strcmp(arr[i],arr[j]) > 0) {
                char tmp[1001] ; 
                strcpy(tmp, arr[i]);
                strcpy(arr[i] ,arr[j]);
                strcpy(arr[j] ,tmp);
            }
        }
    }
    
    for(int i = 0 ; i < arrIdx ; i ++) {
        printf("%s\n", arr[i]);
    }
    return 0;
}