/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi_and_nullck.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 18:02:03 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/05/31 17:58:58 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_nbr(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int atoi_and_nullck(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	ret = 0;
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
	if (ret > 2147483648 || (ret == 2147483648 && sign > 0))
		print_error();
	return (ret);
}