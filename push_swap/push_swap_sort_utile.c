/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utile.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:30:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/05/31 21:46:52 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min_val(t_stack *a)
{
	int		min_val;
	t_stack	*tmp;

	min_val = a->val;
	tmp = a->nxt;
	while (tmp != a)
	{
		if (tmp->val < min_val)
			min_val = tmp->val;
		tmp = tmp->nxt
	}
	return (min_val);
}

int get_max_val(t_stack *a)
{
	int		max_val;
	t_stack	*tmp;

	max_val = a->val;
	tmp = a->nxt;
	while (tmp != a)
	{
		if (tmp->val > max_val)
			max_val = tmp->val;
		tmp = tmp->nxt
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
	tail = a->prv;
	while (a != tail)
	{
		a = a->nxt
		len++;
	}
	return (len);
}

