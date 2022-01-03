/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 15:25:07 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/01/03 18:18:13 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size != 0)
	{
		while (src[i] && i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (src_len);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	len;
	char	*str;

	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		if (i < s1_len)
			str[i] = s1[i];
		else
			str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

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
	re = (char *)malloc(sizeof(char) * (len + 1));
	if (!re)
		return (0);
	ft_strlcpy(re, s + start, len + 1);
	return (re);
}
