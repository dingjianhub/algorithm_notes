# Uva1585 Score

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4460)

[uDubug地址](https://www.udebug.com/UVa/1585)

## 1.题目描述

![Uva1585](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1585_1.png)

![Uva1585](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1585_2.png)

## 2. 思路解析

+ 遇到 X 不处理
+ 遇到 O 处理，设置一个数，记录 O 连续的次数

## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva1585.c)

```c
#include <stdio.h>
#include <string.h>

char s[100];

int main()
{
    int n;
    scanf("%d",&n);
    while (n--) {
        scanf("%s",s);
        int len = strlen(s);
        int ans = 0;
        int sum = 0;
        int flag = 1;
        for(int i = 0;i < len;i++){
            if (s[i] == 'O'){
                flag = 1;
                ans++;
            }
            else {
                flag = 0;
                ans = 0;
            }
            if(flag){
                sum += ans;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

```

