/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <wonjchoi@42seoul.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:40:01 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/12 23:32:04 by choewonju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	find;
	char	*back;
	int				i;

	i = ft_strlen(s);
	back = (char*)s;
	find = (char)c;
	while (i > 0)
	{
		if(back[i] == find)
			return (back + i);
		i--;
	}
	if (back[i] == find)
		return (back);
	return (0);
}


