/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <wonjchoi@42seoul.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:01:56 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/14 18:12:26 by choewonju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*re;

	len = ft_strlen(s1);
	re = (char *)malloc(sizeof(char) * (len + 1));
	if (!re)
		return (0);
	i = -1;
	while (++i < len)
		re[i] = s1[i];
	re[i] = 0;
	return (re);
}
