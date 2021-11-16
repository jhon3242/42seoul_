/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:46:05 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/11/17 00:28:30 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n /= 10;
		n *= -1;
		ret += 2;
	}
	while (n)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*re;

	len = ft_intlen(n);
	re = (char *)malloc(sizeof(char) * (len + 1));
	if (!re)
		return (0);
	re[len--] = 0;
	nb = n;
	if (nb == 0)
    {
        re[0] = '0';
        return (re);
    }
	if (nb < 0)
	{
		nb *= -1;
		re[0] = '-';
	}
	while (len >= 0)
	{
		re[len--] = '0' + nb % 10;
		nb /= 10;
	}
	return (re);
}
