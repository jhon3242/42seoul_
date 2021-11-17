/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:21:27 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/17 13:37:34 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_up(int c)
{
	return (('A' <= c) && (c <= 'Z'));
}

int	ft_tolower(int c)
{
	if (is_up(c))
		return (c + 32);
	return (c);
}
