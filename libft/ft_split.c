/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:08:33 by choewonjun        #+#    #+#             */
/*   Updated: 2021/11/17 17:01:57 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	is_sep(char const *s, char c)
{
	if (*s == c)
		return (1);
	return (0);
}

int	ct_wd(char const *s, char c)
{
	int	i;
	int	flag;
	int	re;

	i = 0;
	flag = 0;
	re = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s + i, c))
			i++;
		if (s[i] && !is_sep(s + i, c))
			re++;
		while (s[i] && !is_sep(s + i, c))
			i++;
	}
	return (re);
}

void	wd_split(char *dst, char *from, char *untill)
{
	while (from < untill)
		*(dst++) = *(from++);
	*dst = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	char	*from;
	char	*start;
	int		wd_ct;
	int		i;

	wd_ct = ct_wd(s, c);
	i = 0;
	start = (char *)s;
	if (!(re = (char **)malloc(sizeof(char *) * (wd_ct + 1))))
		return (0);
	while (*start)
	{
		if (!is_sep(start, c))
		{
			from = start;
			while (*start && !is_sep(start, c))
				start++;
			re[i] = (char *)malloc(start - from + 1);
			wd_split(re[i++], from, start);
		}
		start++;
	}
	re[i] = 0;
	return (re);
}
