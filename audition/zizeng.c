#include <stdio.h>

int main()
{
    int a = 1;
    int b = 2;
    int c = 0;
    
    //自增和自减操作后缀优先级高
    c = a+++b;

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}
