#include <stdio.h>

int main()
{
    char letter;
    int flag = 1;
    while (scanf("%c",&letter) != EOF) {
        if (letter == '"') {
            printf("%s",flag ? "``" : "''"); flag = !flag;
        }
        else{
            printf("%c",letter);
        }
    }
    return 0;
}
