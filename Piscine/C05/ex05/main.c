#include <stdio.h>

int    ft_sqrt(int nb)
{
    int    i;

    if (nb <= 0)
        return (0);
    i = 1;
    while (i * i < nb)
        i++;
    if (i * i == nb)
        return (i);
    return (0);
}

int main()
{
    int a;
    for (int i = 0 ; i < 100 ; i++)
    {
        a = ft_sqrt(i);
        printf("%d\n", a);
    }
}
