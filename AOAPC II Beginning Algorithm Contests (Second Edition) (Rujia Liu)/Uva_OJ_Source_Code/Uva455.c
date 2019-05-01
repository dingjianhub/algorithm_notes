#include <stdio.h>
#include <string.h>

char s[85];

int main()
{
    int q;
    scanf("%d",&q); // 读入测试的组数
    getchar(); // 读取一个空行，然后读入 q组 测试数据
    while (q--) {
        scanf("%s",s); //因为读取的内容不含空格，可以使用 %s 读入一行
        getchar();
        getchar();//读取空行
        //开始处理
        int len = strlen(s);
        int ans = 1;
        int begin = 0; //标记起点
        int flag = 0; // 标记，ans 是否满足最小周期
        for (ans = 1;ans <= len;ans++){ //增加ans从1到len
            // 思路为枚举：第一个 ans 周期 和 后面的周期一一比对，全部符合最小周期，则ans为最小周期
            int tmp = 0;
            if (len % ans == 0) tmp = len / ans - 1; // 如果可以被整除
            else tmp = (int)(len / ans + 0.5); // 无法被整除
            for (int i = 1;i <= tmp;i++){ //需要比对的组数
                // amanamanamanaman 16/4 - 1 = 3 组
                //bbabb
                //abababababababbababababab
                //每个位置都需要比对
                //cdfecdfecdf
                //caccac
                for (int k = 0;k < ans;k++){ // 上面tmp的处理可以避免出现 0 + 4 * 4 + 3 数组越界情况
                    if (s[begin + k] == s[begin + ans * i + k]){
                        flag = 1;
                    }
                    else {
                        flag = 0;
                        break;
                    }
                    //printf("%c %c\n",s[begin + k],s[begin + ans * i + k]);
                }
                if (!flag){ // 注意此处添加判断，跳出循环，开始下一个 ans 的判断
                    break;
                }
            }
            if (flag){
                if (q + 1 == 1){ // 如果只有一组数据，那么输出不加空行
                    printf("%d\n",ans);
                }
                else {
                    printf("%d\n\n",ans);
                }
                break;
            }
        }  // end of for
        if (!flag) { // 多组数据的情况，输出格式为每个数据后加一个空行
            if (q + 1 != 1) printf("%d\n\n",ans - 1);
            else printf("%d\n",ans - 1);
        }
    } //end of while
    return 0;
}
/*
* Uva地址：https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=396
* uDebug地址：https://www.udebug.com/UVa/455
*/
