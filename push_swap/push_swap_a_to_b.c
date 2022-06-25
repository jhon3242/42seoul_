/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:47:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 17:55:39 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sorting_a(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	if (len == 2 || len == 3)
	{
		if ((*a)->val > (*a)->nxt->val)
			do_op("sa", a, b, cmd);
		if (len == 3 && !is_accend(*a, len))
		{
			do_op("ra", a, b, cmd);
			
			do_op("sa", a, b, cmd);
			do_op("rra", a, b, cmd);
			if ((*a)->val > (*a)->nxt->val)
				do_op("sa", a, b, cmd);
		}
	}
}

static void divide_a(t_stack **a, t_stack **b, int len, t_info *i, t_cmd **t)
{
	while (len-- > 0)
	{
		if ((*a)->val > i->pvt_greater)
		{
			do_op("ra", a, b, t);
			(i->cnt_ra)++;
		}
		else if ((*a)->val <= i->pvt_less)
		{
			do_op("pb", a, b, t);
			(i->cnt_pb)++;
		}
		else
		{
			do_op("pb", a, b, t);
			do_op("rb", a, b, t);
			(i->cnt_pb)++;
			(i->cnt_rb)++;
		}
	}
}

void	a_to_b(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	t_info info;

	if (len <= 3)
	{
		if (!is_accend(*a, len))
			sorting_a(a, b, len, cmd);
		return ;
	}
	info = (t_info){0, };
	set_pivot(*a, len, 'a', &info);
	divide_a(a, b, len, &info, cmd);
	both_rroll(a, b, info.cnt_rb, cmd);
	a_to_b(a, b, info.cnt_ra, cmd);
	b_to_a(a, b, info.cnt_rb, cmd);
	b_to_a(a, b, info.cnt_pb - info.cnt_rb, cmd);
}