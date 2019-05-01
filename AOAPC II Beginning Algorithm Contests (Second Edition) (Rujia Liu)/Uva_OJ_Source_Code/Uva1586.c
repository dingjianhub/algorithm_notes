#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s[85];
double n[] = {12.01,1.008,16.00,14.01};

int main()
{
    int q;
    scanf("%d",&q);
    while (q--) {
        scanf("%s",s);
        int len = strlen(s);
        double sum = 0;
        for (int i = 0;i < len;i++){
            while (isalpha(s[i]) && i < len) {
                char plus[10];
                char tmp = s[i];
                i++;//开始处理数字部分
                int order = 0;
                while (isdigit(s[i])) { //数字存入数组待用
                    plus[order++] = s[i++];
                }
                //printf("i is %d, ",i);
                int plus_plus = 1;
                int plus_sum = 0;
                //printf("order is %d , ",order);
                if (order > 0){ //元素不为0的情况,注意，order要回退 1 ！！！
                    for (int k = order - 1;k >= 0;k--){
                        plus_sum += (plus[k] - '0') * plus_plus;
                        //printf("plus[k] - '0':%d , ",plus[k] - '0');
                        plus_plus *= 10;
                    }
                }
                else{ //元素为0的情况
                    plus_sum = 1;
                }
                // 计算该元素的总值
                //printf("the char is %c , plus_sum is %d \n",tmp,plus_sum);
                switch (tmp) { // 元素 * 的mol质量和
                    case 'C':{
                        sum += plus_sum * n[0];
                        break;
                    }
                    case 'H':{
                        sum += plus_sum * n[1];
                        break;
                    }
                    case 'O':{
                        sum += plus_sum * n[2];
                        break;
                    }
                    case 'N':{
                        sum += plus_sum * n[3];
                        break;
                    }
                } //end switch
            } // end while of
        } //end for
        printf("%.3f\n",sum);
    } //end scanf while loop
    return 0;
}
