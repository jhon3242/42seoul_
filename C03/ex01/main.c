#include <string.h>



int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int    i;

    i = 0;
    while (s1[i] && s2[i] && i < n)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (i == n)
        return (0);
    else
        return (s1[i] - s2[i]);
}


int main()
{
    char s1[] = "this is test";
    char s2[] = "thas";
    
    int a = ft_strncmp(s1, s2, 3);
    int b = strncmp(s1, s2, 3);
    
    return 0;
}

