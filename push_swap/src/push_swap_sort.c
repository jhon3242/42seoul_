/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:30:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 23:12:20 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_minmax(t_stack **a, t_stack **b, int min_val, t_cmd **cmd)
{
	if ((*b)->val == min_val)
		do_op("pa", a, b, cmd);
	else
	{
		do_op("pa", a, b, cmd);
		do_op("ra", a, b, cmd);
	}
}

static void	sort_3(t_stack **a, t_stack **b, t_cmd **cmd)
{
	if ((*a)->val == get_min_val(*a))
	{
		do_op("sa", a, b, cmd);
		do_op("ra", a, b, cmd);
	}
	else if ((*a)->val == get_max_val(*a))
		do_op("ra", a, b, cmd);
	else
	{
		if ((*a)->nxt->val == get_min_val(*a))
			do_op("sa", a, b, cmd);
		else
			do_op("rra", a, b, cmd);
	}
}

static void	sort_4_5(t_stack **a, t_stack **b, t_cmd **cmd)
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
			do_op("pb", a, b, cmd);
			pb_count++;
		}
		else
			do_op("ra", a, b, cmd);
	}
	if (is_decend(*a, 3))
		reverse_stack(a, b, 3, cmd);
	else if (!is_accend(*a, 3))
		sort_3(a, b, cmd);
	while (pb_count-- > 0)
		sort_minmax(a, b, min_val, cmd);
}

void	sort_by_len(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	if (len == 3)
		sort_3(a, b, cmd);
	else if (len == 4 || len == 5)
		sort_4_5(a, b, cmd);
	else
		a_to_b(a, b, len, cmd);
}
