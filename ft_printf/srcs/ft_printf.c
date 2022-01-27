/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:14:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/01/27 22:53:49 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void op(const char *str, va_list ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str ++;
			if (*str == 'c')
				ft_putchar_fd(va_arg(ap, ))
			else if (*str == 'd')
				ft_putnbr_fd(va_arg(ap, int), 1);
			else
				write(1, str++, 1);
		}
		else
			write(1, str++, 1);
	}
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	op(str, ap);
	va_end(ap);
	return (0);
}
