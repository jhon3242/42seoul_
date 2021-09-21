/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:14 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/20 14:15:15 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*p;
	int			*tmp;
	long long	size;

	if (min >= max)
		return (0);
	size = max - min;
	p = (int *)malloc(sizeof(int) * (size));
	if (!p)
		return (0);
	tmp = p;
	while (min < max)
	{
		*p = min;
		p++;
		min++;
	}
	return (tmp);
}
