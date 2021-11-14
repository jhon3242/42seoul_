/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:23:50 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/14 19:51:18 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;
	int		i;

	find = (unsigned char)c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == find)
			return ((char *)s + i);
	}
	if (s[i] == find)
			return ((char *)s + i);
	return (0);
}

