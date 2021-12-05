/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:47:00 by choewonju         #+#    #+#             */
/*   Updated: 2021/12/05 19:32:04 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*new_dst;
	char	*new_src;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		new_dst = (char *)dst;
		new_src = (char *)src;
		while (len--)
			*new_dst++ = *new_src++;
	}
	else
	{
		new_dst = (char *)dst + (len - 1);
		new_src = (char *)src + (len - 1);
		while (len--)
			*new_dst-- = *new_src--;
	}
	return (dst);
}
