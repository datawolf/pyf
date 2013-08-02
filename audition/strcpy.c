#include <stdio.h>


char *mystrcpy(char *dest, const char *src)
{
    if (src == NULL || dest == NULL)
      return NULL;
    
    if (src == dest)
      return dest;

    while ( (*dest++ = *src++) != '\0')
      ;

    return dest;
}


int main(int argc, char **argv)
{
    char *str1 = "wanglong";
    char str[20];

    mystrcpy(str, str1);

    printf("%s\n", str);
}
