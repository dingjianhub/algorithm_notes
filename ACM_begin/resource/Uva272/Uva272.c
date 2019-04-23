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
    //printf("Hello World!\n");
    return 0;
}

// "To be or not to be," quoth the Bard, "that is the question".
//int main(){
//    char letter;
//    scanf("%c",&letter);
//    printf("%c",letter);
//    scanf("%c",&letter);
//    printf("%c",letter);
//}
