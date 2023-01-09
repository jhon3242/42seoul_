/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_libft2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:01:23 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 17:16:23 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static size_t	get_word_cnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
			if (!*s)
				break; 
		}
		++s;
	}
	return (cnt);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s && *s != c)
	{
		++s;
		++i;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	word_len;
	size_t	i;

	if (!s)
		return (0);
	ret = ft_malloc(sizeof(char *) * (get_word_cnt(s, c) + 1));
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			word_len = get_word_cnt(s, c);
			ret[i] = ft_malloc(word_len + 1);
			ft_strlcpy(ret[i++], s, word_len + 1);
			s += word_len - 1;
		}
		++s;
	}
	ret[i] = 0;
	return (ret);
}