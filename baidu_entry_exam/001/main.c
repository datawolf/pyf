#include <stdio.h>
#include <string.h>




int get_string(char *str, int *loc, int l, int r)
{
    int n = strlen(str);
    while (l >= 0 && r <= n-1 && str[l] == str[r])
    {
        l--;
        r++;
    }
    *loc = l+1;
    return r-l-1;

}

int find_palindrome(char *str, int *start)
{
    int n = strlen(str);
    int longest = 0;
    int i;
    int p1, p2;
    int loc;
    if (n == 0)
    {
        *start = 0;
        return 0;
    }

    for (i = 0; i < n-1; i++)
    {
        p1 = get_string(str, &loc, i, i);
        if (p1 > longest)
        {
            *start = loc;
            longest = p1;
        }


        p2 = get_string(str, &loc, i, i+1);
        if (p2 > longest)
        {
            *start = loc;
            longest = p2;
        }
    }

    return longest;
}
int main(int argc, char *argv)
{
    char str[200] = {0};
    char res[200] = {0};
    int len;
    int start;

    freopen("input.txt", "r", stdin);

    while (scanf("%s", str) != EOF)
    {
        len =  find_palindrome(str, &start);
        strncpy(res, str+start, len);
        res[len] = '\0';
        printf("%s\n", res);
    }
    
    return 0;
}
