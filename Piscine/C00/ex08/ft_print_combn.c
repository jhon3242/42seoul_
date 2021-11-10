#include <unistd.h>
char    g_arr[10];


void    init_arr(int n)
{
    int i;
    i = 0;
    while (i <= n )
        g_arr[i++] = '0';
    g_arr[n] = '\0';
}
/*
void    loop(int n, int index)
{
    while (g_arr[0] <= 10 - n + '0')
    {
        g_arr[1] = g_arr[0] + 1;
        while (g_arr[1] <= 10 - n + 1 + '0')
        {
            g_arr[2] = g_arr[1] + 1;
            while (g_arr[2] <= 10 - n + 2 + '0')
            {
                write(1, g_arr, n);
                write(1, ", ", 2);
                g_arr[2]++;
            }
            g_arr[1]++;
        }
        g_arr[0]++;
    }
}
*/

int ft_last_ck(char *arr, int n)
{
    int i;
    char   ch;
    
    i = 0;
    while (i < n)
    {
        ch = arr[i];
        if (arr[i] != 10 + i - n + '0')
            return (0);
        i++;
    }
    return (1);
}

void    l(int n, int index)
{
    if (index < n - 1)
    {
        while (g_arr[index] <= '9' - n + index + 1)
        {
            g_arr[index + 1] = g_arr[index] + 1;
            l(n, index + 1);
            g_arr[index]++;
        }
        
    }
    else
    {
        while (g_arr[index] <= '9')
        {
            write(1, g_arr, n);
            if (ft_last_ck(g_arr, n))
                return;
            write(1, ", ", 2);
            g_arr[index]++;
        }
    }
    
}

void    ft_print_combn(int n)
{
    init_arr(n);
    l(n,0);
    
}

int main()
{
    ft_print_combn(3);
    return 0;
}
