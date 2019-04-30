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

/*
2
3
13
*/
