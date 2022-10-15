/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 22:20:02 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/16 00:49:48 by wonjchoi         ###   ########.fr       */
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
		a = a->prev;
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

void	set_pivot(t_stack *a, int len, char target_stack, t_info *info)
{
	int	*arr;
	int	div;

	arr = init_arr(a, len); // a 스택에 맨 꼭대기 부터 len 길이 만큼 배열로 만들어줌 
	//	len 길이 만큼만 배열로 만들어주는 이유는 이 함수를 재귀적으로 사용하기 때문에 
	//	a 스택 len 이상 아래 부분은 이미 정렬되어 있을 수 있다.
	quick_sort(arr, 0, len - 1); // 만든 배열을 퀵정렬 알고리즘으로 먼저 정렬한다.
	div = len / 3;
	if (len % 3 == 2)
		div++;
	if (target_stack == 'a') // 
	{
		info->next_less = arr[(len - 1) - (2 * div)];
		info->next_greater = arr[(len - 1) - div];
	}
	else if (target_stack == 'b')
	{
		info->next_less = arr[div];
		info->next_greater = arr[2 * div];
	}
	if (arr)
		free(arr);
	arr = 0;
}
