/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:30:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/16 00:48:54 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_val(t_stack *a)
{
	int		min_val;
	t_stack	*tmp;

	min_val = a->val;
	tmp = a->prev;
	while (tmp != a)
	{
		if (tmp->val < min_val)
			min_val = tmp->val;
		tmp = tmp->prev;
	}
	return (min_val);
}

int	get_max_val(t_stack *a)
{
	int		max_val;
	t_stack	*tmp;

	max_val = a->val;
	tmp = a->prev;
	while (tmp != a)
	{
		if (tmp->val > max_val)
			max_val = tmp->val;
		tmp = tmp->prev;
	}
	return (max_val);
}

int	get_stack_len(t_stack *a)
{
	t_stack	*tail;
	int		len;

	if (!a)
		return (0);
	len = 1;
	tail = a->next;
	while (a != tail)
	{
		a = a->prev;
		len++;
	}
	return (len);
}
