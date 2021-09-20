#include <stdio.h>
#include <stdlib.h>
int        g_pm;
int        g_index;
char    *g_ret;

int    is_space_pm(char ch)
{
    if ('\t' <= ch && ch <= '\r')
        return (1);
    if (ch == ' ')
        return (1);
    if (ch == '+' || ch == '-')
    {
        if (ch == '-')
            g_pm *= -1;
        return (1);
    }
    return (0);
}

int    base_ck(char *base)
{
    char    aski[256];
    int        i;

    i = 0;
    while (i < 256)
        aski[i++] = 0;
    while (*base)
    {
        if (*base == '+' || *base == '-')
            return (0);
        if (*base == ' ')
            return (0);
        if ((aski[(int)*base]) == 1)
            return (0);
        else
            aski[(int)*base] = 1;
        base++;
    }
    return (1);
}

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

long long    base_to_i(char *nbr, char *base_from)
{
    int            i;
    long long    ret;

    g_pm = 1;
    ret = 0;
    while(is_space_pm(*nbr))
        nbr++;
    while (*nbr)
    {
        i = 0;
        while (base_from[i])
        {
            if (base_from[i] == *nbr)
                break ;
            i++;
        }
        if (!base_from[i])
            return (0);
        ret = ret * ft_strlen(base_from) + i;
        nbr++;
    }
    return (ret * g_pm);
}

void    i_to_base(long long nbr, char *base, int size)
{
    if (nbr < 0)
        nbr *= -1;
    if (nbr >= size)
    {
        i_to_base(nbr / size, base, size);
        i_to_base(nbr % size, base, size);
    }
    else
        g_ret[g_index++] = base[nbr];
}



char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    long long    i_nb;
    int            tmp;
    int            count;
    if (!base_ck(base_from) || !base_ck(base_to))
        return (0);
    g_index = 0;
    i_nb = base_to_i(nbr, base_from); // 10진수
    tmp = i_nb;
    count = 0;
    while (tmp > 0)
    {
        tmp /= ft_strlen(base_to);
        count ++;
    }
    g_ret = (char *)malloc(sizeof(char) * (count + 1));
    i_to_base(i_nb, base_to, ft_strlen(base_to));
    g_ret[g_index] = 0;
    return (g_ret);
}
    
int main()
{
    printf("%s\n", ft_convert_base("1111", "01", "0123456789abcdef"));
}
