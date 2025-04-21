#include <stdio.h>
#include <string.h>
char upperROT13(char c) {
    if(c + 13 > 'Z') 
        return c+13-'Z' + 'A' - 1;
    else 
        return c+13;
}
char lowerROT13(char c) {
    if(c + 13 > 'z') 
        return c+13-'z' + 'a' - 1;
    else 
        return c+13;   
}
int main(void){
    char str[101];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for(int i = 0; i < strlen(str); i ++) {
        if(str[i]  >= 'A' && str[i]  <= 'Z')
            str[i] = upperROT13(str[i]);
        else if(str[i]  >= 'a' && str[i]  <= 'z')
            str[i] = lowerROT13(str[i]);
    }
    printf("%s\n", str);
    return 0;
}