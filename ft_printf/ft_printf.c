/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 21:14:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/01/24 21:33:33 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int is_conversions(const char *p)
{
	char	*cvs;


	if (*p != '%')
		return (0);
	p++;
	
	return (0);
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	while (*str)
	{
		if (is_conversions(str))
		{

		}
		write(1, str, 1);
	}
}
