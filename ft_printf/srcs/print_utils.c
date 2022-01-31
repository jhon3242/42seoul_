/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:46:42 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/01/30 17:00:12 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	num_len(int n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		n /= 10;
		n *= -1;
		ret += 2;
	}
	while (n != 0)
	{
		n /= 10;
		ret ++;
	}
	return (ret);
}

int	print_persent(void)
{
	int	ret;

	ret = write(1, "%", 1);
	return (ret);
}

int print_str(char *str)
{
	int	ret;

	ret = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	ret = ft_strlen(str);
	return (ret);
}

int print_char(int n)
{
	write(1, &n, 1);
	return (1);
}

int print_nub(int n)
{
	int	ret;

	ret = num_len(n);
	ft_putnbr_fd(n, 1);
	return (ret);
}