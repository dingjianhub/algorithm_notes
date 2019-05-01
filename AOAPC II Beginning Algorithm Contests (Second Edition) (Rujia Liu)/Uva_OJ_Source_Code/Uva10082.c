#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    char s[] = "`12234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int p;
    while ((scanf("%c",&c)) != EOF) {
        for (p = 0; s[p] && c != s[p];p++); // 找出敲错字符的位置
        if (s[p]) putchar(s[p - 1]);
        else putchar(c);
    }
    return 0;
}
