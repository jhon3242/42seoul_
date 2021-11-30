/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:04:03 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/29 14:37:53 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char const *p, char const *set)
{
	while (*set)
	{
		if (*set == *p)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_from(char const *s1, char const *set)
{
	char	*tmp;

	tmp = (char *)s1;
	while (*tmp && is_set(tmp, set))
		tmp++;
	return (tmp);
}

char	*ft_end(char const *s1, char const *set)
{
	char	*tmp;

	tmp = (char *)s1;
	while (*tmp)
		tmp++;
	tmp--;
	while (*tmp && is_set(tmp, set))
		tmp--;
	if (!is_set(tmp, set))
		tmp++;
	return (tmp);
}

char	*ft_from_end_split(char const *s1, char const *set)
{
	char	*from;
	char	*end;
	char	*re;
	int		i;

	from = ft_from(s1, set);
	end = ft_end(s1, set);
	i = -1;
	if (from >= end)
		return (ft_strdup(""));
	re = (char *)malloc(sizeof(char) * (end - from + 1));
	if (!re)
		return (0);
	while (++i < end - from)
		re[i] = from[i];
	re[i] = 0;
	return (re);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*re;
	int		i;

	i = -1;
	if (!s1)
		return (0);
	re = ft_strdup(s1);
	if (!set)
		return (re);
	re = ft_from_end_split(s1, set);
	return (re);
}
