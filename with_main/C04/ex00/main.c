#include <stdio.h>

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main()
{
    int a;
    
    a = ft_strlen("this");
    printf("%d", a);
}
