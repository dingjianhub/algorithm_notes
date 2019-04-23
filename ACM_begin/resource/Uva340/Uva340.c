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
            if (s2[0] == 0) {flag = 1;break;} //读入数据不含0，若为0则退出读取猜测数据的循环，开始下一轮游
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


/*
4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0

Game 2:
    (1,0)
*/
