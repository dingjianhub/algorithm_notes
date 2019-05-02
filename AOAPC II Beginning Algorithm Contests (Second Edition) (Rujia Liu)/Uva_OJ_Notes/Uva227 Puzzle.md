# Uva227 Puzzle

[Uva OJ 题目地址](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=163)

[uDubug地址](https://www.udebug.com/UVa/227)

## 1.题目描述

![Uva227](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva227_1.png)![Uva227](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva227_2.png)

![Uva227](https://github.com/dingjianhub/algorithm_notes/raw/master/pics/Uva227_3.png)



## 2. 思路解析

这道题目错了好多次，要么WA，要么是 PE……

+ PE 1：最后一个 case 的输出不需要增加额外的空行
+ PE 2：输出的有解的地图，中间要添加空格，地图中最后一个字符后面不能加空格（可以一次输出5个字符，可以避免格式问题）

在读取数据时，要添加 `getcahr` 来吃掉换行符号

在移动时，**先考虑是否出界**，不出界，再移动！

总的来说，这题就是一个纯的模拟，需要考虑周全，才能顺利AC

+ PS：在console输出后，**复制结果的话，其中的空格是会被吃掉的**……但是代码逻辑正确的话可以正常AC 

[Codes On GitHub](https://github.com/dingjianhub/Learn_C_Again/blob/master/AOAPC%20II%20Beginning%20Algorithm%20Contests%20(Second%20Edition)%20(Rujia%20Liu)/Uva_OJ_Source_Code/Uva227.c)

```c
#include <stdio.h>
#include <string.h>

char map[5][5];
char direction[100];

int main()
{
    char t;
    int q_sum= 0;
    while (scanf("%c",&t) && t != 'Z') {
        if (q_sum) printf("\n"); //如果还有情况要处理，补上上一次输出后应该要有的一个空行（极易发生PE）
        q_sum++;// puzzle_case++;
        map[0][0] = t;
        for (int i = 1;i < 5;i++) scanf("%c",&map[0][i]);
        getchar();
        for (int i = 1;i < 5;i++){
            for (int k = 0;k < 5;k++){
                scanf("%c",&map[i][k]);
            }
            getchar();
        }
        //getchar();// 此处还需要一次读入！
        // 计算移动的步数
        int tmp_dirc_sum = 0; // BBA0
//        while (scanf("%c",&direction[tmp_dirc_sum]) && direction[tmp_dirc_sum] != '0') {
//            tmp_dirc_sum++;
//        }
        while (fgets(&direction[tmp_dirc_sum],2,stdin) && direction[tmp_dirc_sum] != '0') {
            tmp_dirc_sum++;
        }
//        int dirc_sum = 0;
//        for (int i = 0;i < tmp_dirc_sum;i++){
//            if (direction[i] != 'A' - 33) dirc_sum++;
//        }
        //开始处理方向的问题
        //首先定位空格位置
        int p_x = 0,p_y = 0;
        for (int i = 0;i < 5;i++){
            for (int k = 0;k < 5;k++){
                if (map[i][k] == ' '){
                    p_x = i;
                    p_y = k;
                    break;
                }
            }
        }
        //printf("the p_x is : %d, the p_y is : %d\n",p_x,p_y);
        int flag = 0;
        char tmp_map;
        for (int i = 0;i < tmp_dirc_sum;i++){
            flag = 0;
            switch (direction[i]) { //上移动
                case 'A':{
                    if (p_x - 1 < 0){
                        printf("Puzzle #%d:\n",q_sum);
                        printf("This puzzle has no final configuration.\n");
                        flag = 1;
                        break;
                    }
                    tmp_map = map[p_x][p_y];
                    map[p_x][p_y] = map[p_x - 1][p_y];
                    map[p_x - 1][p_y] = tmp_map;
                    p_x--;
                    break;
                }
                case 'B':{ // 下移动
                    if (p_x + 1 > 4) {
                        printf("Puzzle #%d:\n",q_sum);
                        printf("This puzzle has no final configuration.\n");
                        flag = 1;
                        break;
                    }
                    tmp_map = map[p_x][p_y];
                    map[p_x][p_y] = map[p_x + 1][p_y];
                    map[p_x + 1][p_y] = tmp_map;
                    p_x++;
                    break;
                }
                case 'L':{ //左移动
                    if (p_y - 1< 0) {
                        printf("Puzzle #%d:\n",q_sum);
                        printf("This puzzle has no final configuration.\n");
                        flag = 1;
                        break;
                    }
                    tmp_map = map[p_x][p_y];
                    map[p_x][p_y] = map[p_x][p_y - 1];
                    map[p_x][p_y - 1] = tmp_map;
                    p_y--;
                    break;
                }
                case 'R':{ // 右移动
                    if (p_y + 1 > 4) {
                        printf("Puzzle #%d:\n",q_sum);
                        printf("This puzzle has no final configuration.\n");
                        flag = 1;
                        break;
                    }
                    tmp_map = map[p_x][p_y];
                    map[p_x][p_y] = map[p_x][p_y + 1];
                    map[p_x][p_y + 1] = tmp_map;
                    p_y++;
                    break;
                }
                case ' ':{
                    break;
                }
                case '\n':{
                    break;
                }
                default:{ //如果出现了除去 “ABLR” 以外的字符，则为非法情况，直接输出无解
                    printf("Puzzle #%d:\n",q_sum);
                    printf("This puzzle has no final configuration.\n");
                    flag = 1;
                    break;
                }
            }//end of swicth
            if (flag){
                break;
            }
        }
        if (!flag){ // 注意输出格式！需要添加额外的空格和换行！
            printf("Puzzle #%d:\n",q_sum);
            for (int i = 0;i < 5;i++){
                printf("%c %c %c %c %c\n",map[i][0],map[i][1],map[i][2],map[i][3],map[i][4]);
            }
        }
        getchar();
    }
    return 0;
}

/*
int main(){
//    for (int i = 0;i < 5;i++){
//        fgets(map[i],6,stdin);
//        getchar();
//    }
    for (int i = 0;i < 5;i++){
        for (int k = 0;k < 5;k++){
            scanf("%c",&map[i][k]);
        }
        getchar();
    }
    for (int i = 0;i < 5;i++){
        for (int k = 0;k < 5;k++){
            printf("%c",map[i][k]);
        }
        printf("\n");
    }
}
*/

```

