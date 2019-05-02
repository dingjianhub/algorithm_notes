# Uva1584 Circular Sequence

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=829&page=show_problem&problem=4459)

[uDubug地址](https://www.udebug.com/UVa/1584)

## 1.题目描述

![Uva1584](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1584_1.png)

![Uva1584](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva1584_2.png)

## 2. 思路解析

+ 观察易得，一个长度为 n 的串，一共可以有 n 种的表示。
  + 例如：AGTC 有 AGTC, GTCA, TCAG ,CAGT 表示
+ 那么需要不断的比较这些串，确定出最小的字典序。
+ 这些串的表示有规律可循，就是将前 i 位和最后的 len - i 位拼接即可

## 3.AC代码

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva1584.c)

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[105];
char ans[105];
char tmp[105];

int main()
{
    int n;
    scanf("%d",&n);
    while (n--) {
        scanf("%s",s);
        int len;
        len = strlen(s);
        memcpy(ans,s,len);//默认第一个串是最小字典序
        for (int i = 0; i < len;i++){ // 每个位置都对比过
            int pos = i;
            int pos_tmp = 0;
            //核心就是字符串的“拼接”
            for(pos = i;pos < len;pos++){
                tmp[pos_tmp++] = s[pos];
            }
            for(int j = 0;j < i;j++){
                tmp[pos_tmp++] = s[j];
            }
//            for (int m = 0;m < strlen(tmp);m++){//test the tmp
//                printf("%c",tmp[m]);
//            }
//            printf("\n");
            if (strcmp(tmp,ans) < 0){
                memcpy(ans,tmp,len);
                //break; 不能break！！
            }
        }
        for (int m = 0;m < len;m++){
            printf("%c",ans[m]);
        }
        printf("\n");
    }
    return 0;
}
```

