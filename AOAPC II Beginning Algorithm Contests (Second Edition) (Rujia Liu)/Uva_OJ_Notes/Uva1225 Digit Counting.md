# Uva1225 Digit Counting

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=3666)

[uDubug地址](https://www.udebug.com/UVa/1225)

## 1.题目描述

![Uva1225](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1225_1.png)

![Uva1225](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1225_2.png)

## 2. 思路解析

+ 不要被解释所带偏！！

字符串和数组的题目很多都是模拟的题目，但是这道题目不应该被题目解释所迷惑。人是要去一个个数的，但是解决这道题目，不需要先将数字写下来再数。直接处理每个数字就好

+ 从1 到 N，每个数字单独处理！这是最快的

## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva1225.c)

```c
#include <stdio.h>
#include <string.h>

int time[10];

int main()
{
    memset(time,0,sizeof (time));
    int q;
    scanf("%d",&q);
    while (q--) {
        int n;
        scanf("%d",&n);
        for (int i = 1;i <= n;i++){ //一共有 n 个数字需要处理
            int num = i;
            int m = 0;
            while (num) {
                m = num % 10;
                time[m]++;
                num = num / 10;
            }
        }
        // 输出模块
        for (int i = 0;i < 10;i++){
            if (i == 0) printf("%d",time[i]);
            else {
                printf(" %d",time[i]);
            }
        }
        printf("\n");
        memset(time,0,sizeof (time));
    }
    return 0;
}

```

