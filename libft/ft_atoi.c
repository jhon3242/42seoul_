/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:45:09 by choewonju         #+#    #+#             */
/*   Updated: 2021/12/16 20:04:45 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if ('\t' <= c && c <= '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	nb;
	long	sign;
	size_t	i;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' | str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isnum(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		if (sign > 0 && nb > 9223372036854775807llu)
		return (-1);
		if (sign < 0 && nb > 9223372036854775808llu)
		return (0);
		i++;
	}
	return (nb * sign);
}
