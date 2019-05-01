# Uva340 Master-Mind Hints

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=829&page=show_problem&problem=276)

[uDubug地址](https://www.udebug.com/UVa/340)

## 1.题目描述

![Uva340](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva340.png)

![Uva340](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva340_1.png)

![Uva340](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva340_2.png)

![Uva340](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva340_3.png)

## 2. 思路解析

+ 每次都比对给定序列和猜测序列对应位置的数字，如果相等，那么 `A++`
+ 稍复杂的是求“都出现在2个序列中，但是位置不对的数字个数”

如果计算这样一种情况：同时出现在2个序列中的数，结果为 `B` 。减去前面已经求出来了`A`，得出的就是 “出现在2个序列中，但是位置不对的数字”。

其过程为：

```c
for (int num = 1;num <= 9;num++){ //统计每个数字出现的次数
                int sum_s = 0,sum_s2 = 0;
                for (int i = 0;i < n;i++){
                    if (s[i] == num) sum_s++; // 统计 num 在给定数列 和 猜测数列中出现的次数
                    if (s2[i] == num) sum_s2++;
                }
                /*
                以出现次数少的为准
                举例：1 5 3 5
                     1 2 5 2
                     (1,1)
                */
                if (sum_s < sum_s2) {B = B + sum_s;} //
                else {B = B + sum_s2;}
            }
```



## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva340.c)

```c
#include <stdio.h>

int main()
{
    int s[1010];
    int s2[1010];
    int n;
    int kase = 1; //第几局游戏，初始化为 0
    while (scanf("%d",&n) == 1 && n) {
        int A = 0; // 出现在相同位置且值相同的数字总数
        int B = 0; // 出现s和s2中，但是位置不对的数字总数
        int flag = 0;
        printf("Game %d:\n",kase++);
        for (int i = 0;i < n;i++){ //读取需要猜测的数字行
            scanf("%d",&s[i]);
        }
        while( !flag ){ //读入多行猜测数据
            A = B = 0;
            for (int i = 0;i < n;i++){ //无论数据是否合法，均读入！
                scanf("%d",&s2[i]);
                if (s[i] == s2[i]) A++;
            }
            if (s2[0] == 0) {flag = 1;break;} //读入数据不含0，若为0则退出读取猜测数据的循环，开始下一轮游戏
            for (int num = 1;num <= 9;num++){ //统计每个数字出现的次数
                int sum_s = 0,sum_s2 = 0;
                for (int i = 0;i < n;i++){
                    if (s[i] == num) sum_s++; // 统计 num 在给定数列 和 猜测数列中出现的次数
                    if (s2[i] == num) sum_s2++;
                }
                /*
                以出现次数少的为准
                举例：1 5 3 5
                     1 2 5 2
                     (1,1)
                */
                if (sum_s < sum_s2) {B = B + sum_s;} //
                else {B = B + sum_s2;}
            }
            printf("    (%d,%d)\n",A,B - A);
        }
    }
    return 0;
}
```

