#include <stdio.h>

int    g_pm;

int    is_pm(char c)
{
    if (c == '-' || c == '+')
    {
        if (c == '-')
            g_pm *= -1;
        return (1);
    }
    else
        return (0);
}

int    is_space(char c)
{
    if (('\t' <= c && c <= '\r') || c == ' ')
        return (1);
    else
        return (0);
}

int    ft_atoi(char *str)
{
    int    i;

    i = 0;
    g_pm = 1;
    while (is_space(*str))
        str++;
    while (is_pm(*str))
        str++;
    while ('0' <= *str && *str <= '9')
    {
        i = i * 10 + (*str - '0');
        str++;
    }
    return (i * g_pm);
}

int main()
{
    int a;
    
    a = ft_atoi("   \t \r \n -2147483648");
    printf("%d\n",a);
}
