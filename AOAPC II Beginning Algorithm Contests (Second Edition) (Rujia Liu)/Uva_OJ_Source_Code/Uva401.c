#include <stdio.h>
#include <string.h>

const char *r = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"is not a palindrome.","is a regular palindrome.",
                     "is a mirrored string.","is a mirrored palindrome."};

int main()
{
    char s[25];
    int length = 0;
    int p = 1; //回文标志，默认为 1
    int m = 1; //镜像标志，默认为 1
    char t;
    while (scanf("%s",s) != EOF) {
        length = strlen(s);
        for (int i = 0;i < (length + 1) / 2;i++){ // 从左端和后端开始，同时比较
            if (s[i] != s[length - 1 - i]) p = 0;
            if (s[i] > 'A' && s[i] < 'Z'){ //镜像串的处理
                t = r[s[i] - 'A']; //如果是字母，那么找出它的镜像字母
                if (t != s[length - 1 - i]) m = 0;
            }
            else if(s[i] > '1' && s[i] < '9'){
                t = r[s[i] - '0' + 25];
                if (t != s[length - 1 - i]) m = 0;
            }
        }
        printf("%s -- %s\n\n",s,msg[m*2+p]);
        p = m = 1;
    }
    return 0;
}
