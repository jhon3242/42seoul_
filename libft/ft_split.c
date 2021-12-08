/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:08:33 by choewonjun        #+#    #+#             */
/*   Updated: 2021/12/08 16:02:37 by wonjchoi         ###   ########.fr       */
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
			while (*s && !is_sep(s, c))
				s++;
			if (!*s)
				break ;
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
	int		i;
	char	*g_start;
	char	*g_from;

	i = 0;
	g_start = (char *)s;
	re = (char **)malloc(sizeof(char *) * (ct_wd(s, c) + 1));
	if (!s || !re)
		return (0);
	while (*g_start)
	{
		if (*g_start && !is_sep(g_start, c))
		{
			g_from = g_start;
			while (*g_start && !is_sep(g_start, c))
				g_start++;
			re[i] = (char *)malloc(g_start - g_from + 1);
			if (!re[i])
				return (ft_free(re));
			wd_split(re[i++], g_from, g_start);
		}
		else
			g_start++;
	}
	re[i] = 0;
	return (re);
}
