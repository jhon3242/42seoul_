/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <wonjchoi@42seoul.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:41:49 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/11 17:42:10 by choewonju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*start;
	unsigned char	value;
	size_t		i;

	start = dest;
	value = c;
	i = -1;
	while (++i < n)
		start[i] = value;
	return (dest);
}
