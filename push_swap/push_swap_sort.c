/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:30:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/23 22:12:18 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_minmax(t_stack **a, t_stack **b, int min_val)
{
	if ((*b)->val == min_val)
		do_op("pa", a, b);
	else
	{
		do_op("pa", a, b);
		do_op("ra", a, b);
	}
}

static void	sort_3(t_stack **a, t_stack **b)
{
	if ((*a)->val == get_min_val(*a))
	{
		do_op("sa", a, b);
		do_op("ra", a, b);
	}
	else if ((*a)->val == get_max_val(*a))
		do_op("ra", a, b);
	else
	{
		if ((*a)->nxt->val == get_min_val(*a))
			do_op("sa", a, b);
		else
			do_op("rra", a, b);
	}
}


static void	sort_4_5(t_stack **a, t_stack **b)
{
	int	min_val;
	int	max_val;
	int	pb_count;

	min_val = get_min_val(*a);
	max_val = get_max_val(*a);
	pb_count = 0;
	while (get_stack_len(*a) > 3)
	{
		if ((*a)->val == min_val || (*a)->val == max_val)
		{
			do_op("pb", a, b);
			pb_count++;
		}
		else
			do_op("ra", a, b);
	}
	if (is_decend(*a, 3))
		reverse_stack(a, b, 3);
	else if (!is_accend(*a, 3))
		sort_3(a, b);
	while (pb_count-- >0)
		sort_minmax(a, b, min_val);
}

void	sort_by_len(t_stack **a, t_stack **b, int len)
{
	if (len == 3)
		sort_3(a, b);
	else if (len == 4 || len == 5)
		sort_4_5(a, b);
	else
		a_to_b(a, b, len);
}
