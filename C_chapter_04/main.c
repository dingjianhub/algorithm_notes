#include <stdio.h>
#include <limits.h>

int main()
{
//    printf("\a");
//    printf("test for \\a");
//    printf("it is \\0");
    char string[10];
    scanf("%s",string);
    printf("%s\n",string);
    printf("%zd",sizeof (string));
    printf("the Maximum int value of this system is = %d\n",INT_MAX);
//    printf("to test it %s.\n",string);

    return 0;
}
