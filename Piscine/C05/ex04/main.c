#include <stdio.h>

int    ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    if (index == 0)
        return (0);
    if (index <= 2)
        return (1);
    return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

int main()
{
    int a;
    
    for (int i = 0 ; i < 10 ; i++)
    {
        a = ft_fibonacci(i);
        printf("%d\n", a);
    }
}
