/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:08:33 by choewonjun        #+#    #+#             */
/*   Updated: 2021/11/19 18:35:27 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char const *s, char c)
{
	if (*s == c)
		return (1);
	return (0);
}

int	ct_wd(char const *s, char c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		if (!is_sep(s, c))
		{
			ret++;
			while (is_sep(s, c))
				s++;
		}
		s++;
	}
	return (ret);
}

void	wd_split(char *dst, char *from, char *untill)
{
	while (from < untill)
		*(dst++) = *(from++);
	*dst = 0;
}

char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	char	*from;
	char	*start;
	int		i;

	i = 0;
	start = (char *)s;
	if (!s || !(re = (char **)malloc(sizeof(char *) * (ct_wd(s, c) + 1))))
		return (0);
	while (*start)
	{
		if (!is_sep(start, c))
		{
			from = start;
			while (*start && !is_sep(start, c))
				start++;
			if(!(re[i] = (char *)malloc(start - from + 1)))
				return (ft_free(re));
			wd_split(re[i++], from, start);
		}
		start++;
	}
	re[i] = 0;
	return (re);
}
