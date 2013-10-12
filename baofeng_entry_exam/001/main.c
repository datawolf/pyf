#include <stdio.h>
#include <string.h>

void reverse(char *str, int l, int r)
{
    char tmp;
    while(l < r)
    {
        tmp = str[l];
        str[l] = str[r];
        str[r] = tmp;
        l++;
        r--;
    }
}

int main(int argc, char **argv)
{
    char str[100];
    int num;
    int len;

    freopen("input.txt", "r", stdin);

    while(scanf("%s %d", str, &num) != EOF)
    {
        len = strlen(str);
        reverse(str, 0, len-1);
        reverse(str, 0, num-1);
        reverse(str, num, len-1);

        printf("%s\n", str);
    }
    return 0;
}
