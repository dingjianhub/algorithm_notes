# Uva401 Palindromes

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=829&page=show_problem&problem=342)

[uDubug地址](https://www.udebug.com/UVa/401)

## 1.题目描述

![Uva401_1](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva401_1.png)

![Uva401_2](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva401_2.png)

## 2. 思路解析

设置一个数组 `char s` 来存放输入的字符串

设置一个数组 char *r 来存放镜像字符

+ 对于回文数

第 `i` 个字符 和 第 `length - i - 1` 字符个应该相等

+ 对于镜像数

找出其镜像字符，比较镜像字母是否和 `length - i - 1` 相等

+ 输出的技巧

本题中，输出可以使用switch语句，但是显得繁琐。观察可以发现规律，如果一个是回文镜像数，那么它必须又是回文数，又是镜像数。那么可以如此取巧：

```c
const char *msg[] = {"is not a palindrome.","is a regular palindrome.",
        				"is a mirrored string.","is a mirrored palindrome."};
printf("%s -- %s\n\n",s,msg[m*2+p]);// m为是否为镜像标志，m = 1为镜像数
```



## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva401.c)

```c
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

```

