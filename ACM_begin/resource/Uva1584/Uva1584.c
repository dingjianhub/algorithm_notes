#include <stdio.h>
#include <string.h>

char s[105];
char ans[105];
char tmp[105];

int main()
{
    int n;
    int len;
    scanf("%d",&n);
    while (n--) {
        scanf("%s",s);
        len = strlen(s);
        memcpy(ans,s,len);
        for (int i = 0; i < len;i++){
            for(int k = i;k < len;k++){
                tmp[k] = s[k];
            }
            for(int j = 0;j < i;j++){
                tmp[j] = s[j];
            } //ans更新
            if (ans[i] < tmp[i]){

            }
        }

    }
    return 0;
}
