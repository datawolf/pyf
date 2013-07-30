#include <stdio.h>

void func(int param1, int param2, int param3)
{
    int var1 = param1;
    int var2 = param2;
    int var3 = param3;

    printf("&param1:0X%08X\n", &param1);
    printf("&param2:0X%08X\n", &param2);
    printf("&param3:0X%08X\n", &param3);

    printf("&var1:0X%08X\n", &var1);
    printf("&var2:0X%08X\n", &var2);
    printf("&var3:0X%08X\n", &var3);
}

int main()
{
    func(1, 2, 3);
    return 0;
}
/*
&param1:0XBFB6F1C0
&param2:0XBFB6F1C4
&param3:0XBFB6F1C8
&var1:0XBFB6F1A4
&var2:0XBFB6F1A8
&var3:0XBFB6F1AC
*/
