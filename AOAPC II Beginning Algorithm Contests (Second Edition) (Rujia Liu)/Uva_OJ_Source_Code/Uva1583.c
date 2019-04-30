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
