#include <stdio.h>

char str[51];
int main(void) {
    int T;
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i ++) {
        scanf("%s",str);
        int c = 0;
        for(int j = 0; str[j]&& c >= 0 ; j ++)
            str[j] == '(' ? c++ : c--;
        printf("%s\n", c == 0 ? "YES" : "NO");
    }
    return 0;
}