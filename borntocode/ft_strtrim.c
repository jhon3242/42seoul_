/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:04:03 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/14 21:00:18 by choewonjun       ###   ########.fr       */
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
	if (!(re = ft_strdup(s1)))
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
