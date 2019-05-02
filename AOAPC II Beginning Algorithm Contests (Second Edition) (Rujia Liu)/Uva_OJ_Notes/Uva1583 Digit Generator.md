# Uva1583 Digit Generator

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=829&page=show_problem&problem=4458)

[uDubug地址](https://www.udebug.com/UVa/1583)

## 1.题目描述

![Uva1583](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1583_1.png)

![Uva1583](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1583_2.png)

![Uva1583](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1583_3.png)

## 2. 思路解析

+ 以下解法来自于《算法竞赛入门经典（第二版）》

![Uva1583](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1583_4.png)

## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva1583.c)

```c
#include <stdio.h>
#include <string.h>

int ans[100005];

int main()
{
    memset(ans,0,sizeof(ans));
    for (int i = 1;i <= 100000;i++){ //将前m个数字和它的生成元存在 ans[] 数组中，查表即可
        int x = i;
        int y = i;
        while (x > 0){
            y += x % 10;
            x = x / 10;
        }
        if (ans[y] == 0 || i < ans[y]) ans[y] = i; //有的数字不存在最小生成元，就保持其为 0
    }
    //测试
//    for(int i = 0;i < 1000;i++) {
//       printf("%d %d\n",i,ans[i]);
//    }

    int t;
    scanf("%d",&t);
    while (t--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}

```

