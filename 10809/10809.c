#include <stdio.h>
#include <string.h>
int main(void) {
    char word[101];
    scanf("%s", word);
    for(char c = 'a' ; c <= 'z' ; c++) {
        int flags = -1;
        for(int i = 0 ; i < strlen(word); i++) {
            if(word[i] == c) {
                flags = i;
                break;
            }
        }
        printf("%d ",flags);
    }
    return 0;
}