#include <stdio.h>

int main()
{
    int routes_sum = 0;
    int arrive = 0;
    int routes[105][2];
    scanf("%d%d",&routes_sum,&arrive);
    for (int i = 0;i < routes_sum;i++){
        scanf("%d%d",&routes[i][0],&routes[i][1]);
    }
    int flag = 1;
    while (flag) {
        for (int i = 0;i < routes_sum;i++){
            if (arrive <= routes[i][0]){
                printf("%d\n",i+1);
                flag = 0;
                break;
            }
            routes[i][0] += routes[i][1];
            printf("the %dth time is %d\n",i+1,routes[i][0]);
        }
//        flag++;
    }

//    printf("Hello World!\n");
    return 0;
}
