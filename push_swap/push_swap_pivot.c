/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:20:02 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/05/31 22:40:05 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*init_arr(t_stack *a, int len)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		print_error();
	i = 0;
	while (i < len)
	{
		arr[i] = a->val;
		a = a->nxt;
		i++;
	}
	return (arr);
}

static void assign_pivot(int *arr, int len, t_info *info)
{
	int	i;
	int	j;
	int	less_cnt;

	i = 0;
	while (i < len)
	{
		j = 0;
		less_cnt = 0;
		while (j < len)
		{
			if (arr[i] < arr[j])
				less_cnt++;
			j++;
		}
		if (less_cnt == info->idx_pvt_less)
			info->pvt_less = arr[i];
		else if (less_cnt == info->idx_pvt_greater)
			info->pvt_greater = arr[i];
		i++;
	}
}

void set_pivot(t_stack *a, int len, char target_stack, t_info *info)
{
	int	*arr;
	int	div;

	arr = init_arr(a, len);
	div = len / 3;
	if (len % 3 == 2)
		div++;
	if (target_stack == 'a')
	{
		info->idx_pvt_less = (len - 1) - (2 * div);
		info->idx_pvt_greater = (len - 1) - div;
	}
	else if (target_stack == 'b')
	{
		info->idx_pvt_less = div;
		info->idx_pvt_greater = 2 * div;
	}
	assign_pivot(arr, len, info);
	if (arr)
		free(arr);
	arr = 0;
}