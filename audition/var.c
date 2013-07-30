/**
 * 查看变量在内存中的分配情况
 *
 */

#include <stdio.h>
int g1 = 0, g2 = 0, g3 = 0;

int main(int argc, char **argv)
{
    static  int s1 = 0, s2 = 0, s3 = 0;
    int v1 = 0, v2 = 0, v3 = 0;

    printf("Global :\n");
    printf("0x%08x\n", &g1);
    printf("0x%08x\n", &g2);
    printf("0x%08x\n", &g3);

    printf("Local :\n");
    printf("0x%08x\n", &v1);
    printf("0x%08x\n", &v2);
    printf("0x%08x\n", &v3);

    printf("Static :\n");
    printf("0x%08x\n", &s1);
    printf("0x%08x\n", &s2);
    printf("0x%08x\n", &s3);

    return 0;
}
/*
Global :
0x0804a020
0x0804a024
0x0804a028
Local :
0xbfb90084
0xbfb90088
0xbfb9008c
Static :
0x0804a02c
0x0804a030
0x0804a034
*/
