#include <string.h>

int ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2)
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

int main()
{
    char s1[] = "this is test";
    char s2[] = "this is test";
    
    int a = ft_strcmp(s1, s2);
    int b = strcmp(s1, s2);
    return 0;
}

