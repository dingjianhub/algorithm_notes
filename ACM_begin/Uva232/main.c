#include <stdio.h>
#include <string.h>

char s[15][15];
int pos[15][15];

int main()
{
    int q_sum = 0;
    int rows,colums;
    memset(pos,0,sizeof (pos));
    while (scanf("%d",&rows) && rows != 0){
        scanf("%d",&colums);
        memset(pos,0,sizeof (pos));
        if (q_sum) printf("\n");
        q_sum++;
        getchar();
        for (int i = 0;i < rows;i++){
            for (int j = 0;j < colums;j++){
                scanf("%c",&s[i][j]);
            }
            getchar();
        }
//        for (int i = 0;i < across;i++){
//            for (int j = 0;j < down;j++){
//                printf("%c",s[i][j]);
//            }
//            printf("\n");
//        }
        int pos_num = 0;
        for (int i = 0;i < rows;i++){
            for (int j = 0;j < colums;j++){
                if (s[i][j] != '*'){
                    if (j - 1 < 0 || i - 1 < 0){
                        pos[i][j] = ++pos_num;
                    }
                    else if (s[i][j - 1] == '*') {
                        pos[i][j] = ++pos_num;
                    }
                    else if (s[i - 1][j] == '*') {
                        pos[i][j] = ++pos_num;
                    }
                }// end of if
            }
        }
        char tmp_word[15];
        printf("puzzle #%d:\n",q_sum);
        printf("Across\n");
        //char *p_s = s;
        for (int m = 1;m <= pos_num;m++){
            for (int i = 0;i < rows * colums;i++){
                if (pos + i != 0 && (s + i) != '*') printf("  %d",pos + i);
            }
        }
//        for (int i = 0;i < rows;i++){
//            for (int j = 0;j < colums;j++){
//                if (pos[i][j] != 0) printf("%d ",pos[i][j]);
//            }
//            printf("\n");
//        }
    }
    return 0;
}

/*
2 2
AT
*O
6 7
AIM*DEN
*ME*ONE
UPON*TO
SO*ERIN
*SA*OR*
IES*DEA
0
*/
