#include <stdio.h>
#include <string.h>

char s[100];

int main()
{
    int n;
    scanf("%d",&n);
    while (n--) {
        scanf("%s",s);
        int len = strlen(s);
        int ans = 0;
        int sum = 0;
        int flag = 1;
        for(int i = 0;i < len;i++){
            if (s[i] == 'O'){
                flag = 1;
                ans++;
            }
            else {
                flag = 0;
                ans = 0;
            }
            if(flag){
                sum += ans;
            }
        }
        printf("%d\n",sum);
    }
    //printf("Hello World!\n");
    return 0;
}

/*
5
OOXXOXXOOO
OOXXOOXXOO
OXOXOXOXOXOXOX
OOOOOOOOOO
OOOOXOOOOXOOOOX
*/
