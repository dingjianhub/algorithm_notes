#include <stdio.h>
#include <string.h>

char map[5][5];
char direction[100];

int main()
{
    char t;
    int q_sum= 0;
    while (scanf("%c",&t) && t != 'Z') {
        if (q_sum) printf("\n");
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
        int dirc_sum = 0;
        for (int i = 0;i < tmp_dirc_sum;i++){
            if (direction[i] != 'A' - 33) dirc_sum++;
        }
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
                default:{
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
        if (!flag){ // 注意输出格式！需要添加多余的空格和换行！
            printf("Puzzle #%d:\n",q_sum);
//            for (int i = 0;i < 5;i++){
//                for (int k = 0;k < 5;k++){
//                    if (k == 0) printf("%c",map[i][k]);
//                    else printf(" %c",map[i][k]);
//                }
//            }
            for (int i = 0;i < 5;i++){
                printf("%c %c %c %c %c\n",map[i][0],map[i][1],map[i][2],map[i][3],map[i][4]);
//                printf("\n");
            }
            //printf("\n");
        }
        getchar();
        //printf("the dirc_sum is %d\n",dirc_sum);
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

/*
 BCDE
FGHIJ
KLMNO
PQRSY
TUVWX
L0
Z
ABCD
FGHIJ
KLMNO
PQRSY
TUVWX
RRRRA
AAA0
Z
*/
/*
TRGSJ
XDOKI
M VLN
WPABE
UQHCF
ARRBBL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAA
LLLL0
ABCDE
FGHIJ
KLMNO
PQRS
TUVWX
AAAAABBRRRLL0
Z
*/

/*
Puzzle #1:
T R G S J
X O K L I
M D V B N
W P A E
U Q H C F
Puzzle #2:
A B C D
F G H I E
K L M N J
P Q R S O
T U V W X
Puzzle #3:
This puzzle has no final configuration.


Puzzle #1:
This puzzle has no final configuration.

Puzzle #2:
This puzzle has no final configuration.

Puzzle #3:
T R G S J
X O K L I
M D V B N
W P   A E
U Q H C F

Puzzle #4:
This puzzle has no final configuration.

Puzzle #5:
This puzzle has no final configuration.

Puzzle #6:
This puzzle has no final configuration.


Puzzle #3:
T R G S J
X O K L I
M D V B N
W P   A E
U Q H C F

 BCDE

Puzzle #1:
This puzzle has no final configuration.

*/
/*
这题debug了好久，一直都没有找到错误，后来发现，是因为样例数据的格式有些神奇...
比较难调，以及有些别的细节，因为自己观察不细致，也没有发现...导致所有的bug都只能一点点发现

1. 不要选C++5.3.0，应该按照 C++11 5.3.0，好像前者已经废除了gets()，总之如果用前者，编译错

2. 注意观察输入的数据，有一种比较特殊的情况，
    空格在某行的最后一列，而此空行后，就是字符串结束符，
    这种情况要单独处理，将结束符换为空格...
    我当时自己写show()函数检查输出时，就发现了有很多位置不对劲的NULL，
    现在想来，这就是一个很重要的提示了，毕竟学过，
    结束符就是NULL...后来加上 if (maps[i][4] == '\0') 这种情况的处理，格式就没问题了

    所以，注意观察输入数据的格式，十分重要，uva许多题目，对格式的处理都需要十分注意，
    最好先全部复制到一个txt，所有的行尾有没有空格，有没有回车，
    或者行尾是直接的结束符，都要考虑...关键是，基础知识也要敏感，
    比如看到NULL要立刻反应过来，是行尾的换行符导致的，而我之前，就不太敏感...

  3.注意指令的输入后，要把换行符接受了，否则换行符会作为下一组的maps[0]，
    那样就再也退出不了了...我好像就是这么把vj弄崩了一次...

  4.注意指令除了ABLR以外，还有可能出现换行符，有换行符就跳过，
    此外的字符一定非法，故而default 处一定要直接 return 0;
    (BTW，鉴于UVA奇葩数据格式的先例，平时其实还需要考虑更多：
    有没有结束符，有没有空格，对这题而言，这两个如果有，也跳过当作合法数据，不处理，
    至于遇到0的ASCII码不再接收字符，这个容易想到，
    但是要做两个处理，一个接受后面的换行符或结束符，一个字符串末加结束符...)
    这两步的处理并不能合写为一步，cmd[k] = getchar();
    否则WA，因为...说过了getchar()到的不一定是结束符，还可能是换行符
*/
