/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:04:03 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/16 13:35:05 by wonjchoi         ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*re;
	int		i;
	int		j;

	i = -1;
	if (!s1)
		return (0);
	re = ft_strdup(s1);
	if (!re)
		return (0);
	while (re[++i])
	{
		if (is_set(re + i, set))
		{
			j = 0;
			while (re[i + j])
			{
				re[i + j] = re[i + j + 1];
				j++;
			}
			i--;
		}
	}
	return (re);
}
