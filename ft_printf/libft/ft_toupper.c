/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:36:56 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/12/13 17:07:41 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_low(int c)
{
	return ((97 <= c) && (c <= 122));
}

int	ft_toupper(int c)
{
	if (is_low(c))
		return (c - 32);
	return (c);
}
