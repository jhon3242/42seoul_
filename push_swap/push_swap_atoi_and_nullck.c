/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi_and_nullck.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:02:03 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/02 16:44:03 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void apply_sign(int sign, long long *ret)
{
	if (sign < 0)
		*ret =  ~(*ret) + 1;
}

static int is_nbr(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

static int put_sign(const char *str, int *sign)
{
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign *= -1;
		return (1);
	}
	return (0);
}


int atoi_and_nullck(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;

	if (put_sign(str, &sign))
		str++;
	if (!*str)
		print_error();
	while (*str)
	{
		if (is_nbr(*str))
		{
			ret *= 10;
			ret += (*str - '0');
		}
		else
			print_error();
		str++;
	}
	apply_sign(sign, &ret);
	if (ret > 2147483647 || ret < -2147483648)
		print_error();
	return (ret);
}