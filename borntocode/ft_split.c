/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:08:33 by choewonjun        #+#    #+#             */
/*   Updated: 2021/11/14 21:13:31 by choewonjun       ###   ########.fr       */
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

void	wd_split(char **re, char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] && is_sep(s + i, c))
			i++;
		if (s[i] && !is_sep(s + i, c))
			re++;
		while (s[i] && !is_sep(s + i, c))
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	int		wd_ct;

	wd_ct = ct_wd(s, c)
	if(!(re = (char **)malloc(sizeof(char *) * (wd_ct + 1))))
		return (0);
	return (re);
}
