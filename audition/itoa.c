/**
 *
 * 将整形的数字，转换为字符串
 *
 */


#include <stdio.h>
int main( int argc, char **argv)
{
    char    temp[10], str[10];
    int num, i, j;

    i = 0;
    num = 123456;

    while(num)
    {
        temp[i] = num%10 + '0';
        i++;
        num = num/10;
    }
    temp[i] = 0;

    printf("temp = %s\n", temp);
    i = i - 1;
    printf("i = %d\n", i);
    
    j = 0;
    while(i >= 0)
    {
        str[i] = temp[j];
        j++;
        i--;
    }
    str[j] = 0;

    printf("string = %s\n", str);
}

