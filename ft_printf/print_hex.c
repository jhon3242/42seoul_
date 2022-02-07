/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:11:27 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/02/07 15:04:23 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	op(unsigned int num, const char *cmp)
{
	int	ret;

	ret = 0;
	if (num >= 16)
	{
		ret += op(num / 16, cmp);
		ret += op(num % 16, cmp);
	}
	else
	{
		ret += write(1, cmp + num, 1);
	}
	return (ret);
}

int	print_hex(unsigned int num, char fmt)
{
	int	ret;

	ret = 0;
	if (fmt == 'x')
		ret += op(num, "0123456789abcdef");
	else
		ret += op(num, "0123456789ABCDEF");
	return (ret);
}
