/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:08 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/20 16:42:56 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*ret;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (-1);
	i = 0;
	while (i < size)
	{
		ret[i++] = min;
		min++;
	}
	*range = ret;
	return (size);
}
