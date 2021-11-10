/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:31:56 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/16 14:02:43 by choewonju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


long long    g_len;

int    base_ck(char *base)
{
    char    aski[256];
    int        i;

    i = 0;
    while (i < 256)
        aski[i++] = 0;
    i = 0;
    while (base[i])
        i++;
    g_len = i;
    if (g_len <= 1)
        return (0);
    while (*base)
    {
        if (*base == '+' || *base == '-')
            return (0);
        if (aski[(unsigned int)*base] == 1)
            return (0);
        else
            aski[(unsigned int)*base] = 1;
        base++;
    }
    return (1);
}

void    i_to_base(long long nbr, char *base)
{
    if (nbr >= g_len)
    {
        i_to_base(nbr / g_len, base);
        i_to_base(nbr % g_len, base);
    }
    else
    {
        write(1, &base[nbr], 1);
    }
}

void    ft_putnbr_base(int nbr, char *base)
{
    long long    tmp;

    tmp = nbr;
    if (!base_ck(base))
        return ;
    if (tmp < 0)
    {
        write(1, "-", 1);
        tmp *= -1;
    }
    i_to_base(tmp, base);
}

int main()
{
    ft_putnbr_base(-2147483648, "0123456789abcdef");
}
