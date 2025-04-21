#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int arr[4];
    for(int i = 0 ; i < 4 ; i ++)
        scanf("%d", &arr[i]);
    char str[20];
    char str2[20];
    sprintf(str, "%d%d", arr[0],arr[1]);
    sprintf(str2, "%d%d", arr[2],arr[3]);
    char * end;
    printf("%ld\n", strtol(str, &end, 10) + strtol(str2, &end, 10));
    return 0;
}
