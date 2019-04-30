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
        memcpy(ans,s,len);
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
/*
1
GTGA
*/
