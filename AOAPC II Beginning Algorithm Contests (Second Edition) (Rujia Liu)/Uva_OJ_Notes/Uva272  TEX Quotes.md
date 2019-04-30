# Uva272  TEX Quotes

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=829&page=show_problem&problem=208)

[uDubug地址](https://www.udebug.com/UVa/272)

## 1.题目描述

```
在 TeX 中，左双引号是 `` ,右双引号是 '' .
输入一篇包含双引号的文章，你的任务是把它转换成TeX的格式。
样例输入：
"To be or not to be," quoth the Bard, "that
is the question".
样例输出：
``To be or not to be,'' quoth the Bard, ``that
is the question''. 
```

![Uva272](https://github.com/dingjianhub/algorithm_notes/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Notes/pics/Uva272.png)

## 2. 思路解析

+ 本题属于入门难度，非常简单

首先，我们需要不断的读入，直到读取到 `EOF` ，停止读入。

这个问题中，是可以一边读入一边处理的，如果读取的是需要处理的引号，那么就将其替换。这里的引号都是成对出现的，第一次（奇数次）出现的引号是需要更改的，而偶数次出现的是不需要更改的。

+ 这需要设置一个 flag 标记，如果是第一次出现的，那么 flag 取反，下一次出现的不需要替换。

如此，即可解决。



## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva272.c)

```c
#include <stdio.h>

int main()
{
    char letter;
    int flag = 1;
    while (scanf("%c",&letter) != EOF) { //可以边读取边处理
        if (letter == '"') {
            printf("%s",flag ? "``" : "''"); 
            flag = !flag; //取反
        }
        else{
            printf("%c",letter);
        }
    }
    return 0;
}
```

