/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:20:02 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/21 19:34:39 by wonjchoi         ###   ########.fr       */
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

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	pivot = start;
	i = pivot + 1;
	j = end;
	if (start >= end)
		return ;
	while (i <= j)
	{
		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i > j)
			swap(&arr[j], &arr[pivot]);
		else
			swap(&arr[i], &arr[j]);
	}
	quick_sort(arr, start, j - 1);
	quick_sort(arr, j + 1, end);
}

void set_pivot(t_stack *a, int len, char target_stack, t_info *info)
{
	int	*arr;
	int	div;

	arr = init_arr(a, len);
	quick_sort(arr, 0, len - 1);
	div = len / 3;
	if (len % 3 == 2)
		div++;
	if (target_stack == 'a')
	{
		info->pvt_less = arr[(len - 1) - (2 * div)];
		info->pvt_greater = arr[(len - 1) - div];
	}
	else if (target_stack == 'b')
	{
		info->pvt_less = arr[div];
		info->pvt_greater = arr[2 * div];
	}
	if (arr)
		free(arr);
	arr = 0;
}