/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <wonjchoi@42seoul.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:18:05 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/14 18:42:47 by choewonju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	re_len;
	char	*re;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	re_len = ft_strlen(s + start);
	if (re_len < len)
		len = re_len;
	if (!(re = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(re, s + start, len + 1);
	return (re);
}
