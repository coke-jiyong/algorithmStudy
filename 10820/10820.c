#include <stdio.h>
#include <string.h>

int main(void) {
    char str[101];
    while (fgets(str, sizeof(str), stdin)) {
        int upperCnt = 0;
        int lowCnt = 0;
        int spaceCnt = 0;
        int numberCnt = 0;

        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] >= 'a' && str[j] <= 'z')
                lowCnt++;
            else if (str[j] >= 'A' && str[j] <= 'Z')
                upperCnt++;
            else if (str[j] >= '0' && str[j] <= '9')
                numberCnt++;
            else if (str[j] == ' ')
                spaceCnt++;
        }

        printf("%d %d %d %d\n", lowCnt, upperCnt, numberCnt, spaceCnt);
    }
    return 0;
}
