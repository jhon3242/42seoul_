#include <stdio.h>

int    ft_recursive_power(int nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    nb = nb * ft_recursive_power(nb, power - 1);
    return (nb);
}

int main()
{
    int a;
    
    a = ft_recursive_power(-3, 5);
    printf("%d", a);
}