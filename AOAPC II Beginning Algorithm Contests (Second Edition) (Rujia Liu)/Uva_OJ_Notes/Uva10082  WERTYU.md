# Uva10082 WERTYU

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=829&page=show_problem&problem=1023)

[uDubug地址](https://www.udebug.com/UVa/10082)

## 1.题目描述

![Uva272](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva10082_1.png)

![Uva272](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva10082_2.png)

## 2. 思路解析

+ 本题属于入门难度

对于这种需要处理固定字符的问题，最好是将字符存在数组中，以备查询。**避免使用 if 或者 switch 语句。**

+ 注意输入数据的格式，避免格式问题造成的 `WA`

本题中，input 指出，输入的数据都是合法的数据，这样处理起来就简单多了。

**本题可以边读取一边来处理**，每次找出敲错的字符在数组 `s[]` 中的位置，其正确的字母就是该位置 `p - 1`

## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva10082.c) 

```c
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
```
