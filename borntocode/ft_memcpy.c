/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <wonjchoi@42seoul.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:51:54 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/11 18:43:57 by choewonju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	size_t			i;

	if (!dst && !src)
		return (0);
	new_dst = dst;
	new_src = (unsigned char *)src;
	i = 0;
	while (i++ < n)
		*new_dst++ = *new_src++;
	return (dst);
}
