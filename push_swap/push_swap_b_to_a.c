/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:22:03 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 17:53:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sorting_b(t_stack **a, t_stack **b, int len, t_cmd ** cmd)
{
	if (len == 2 || len == 3)
	{
		if ((*b)->val < (*b)->nxt->val)
			do_op("sb", a, b, cmd);
		if (len == 3)
		{
			if (!is_decend(*b, len))
			{
				do_op("rb", a, b, cmd);
				do_op("sb", a, b, cmd);
				do_op("rrb", a, b, cmd);
				if ((*b)->val < (*b)->nxt->val)
					do_op("sb", a, b, cmd);
			}
			do_op("pa", a, b, cmd);
		}
		do_op("pa", a, b, cmd);
	}
	do_op("pa", a, b, cmd);
}

static void divide_b(t_stack **a, t_stack **b, int len, t_info *i, t_cmd **t)
{
	while (len-- > 0)
	{
		if ((*b)->val >= i->pvt_greater)
		{
			do_op("pa", a, b, t);
			++(i->cnt_pa);
		}
		else if ((*b)->val < i->pvt_less)
		{
			do_op("rb", a, b, t);
			++(i->cnt_rb);
		}
		else
		{
			do_op("pa", a, b, t);
			do_op("ra", a, b, t);
			++(i->cnt_pa);
			++(i->cnt_ra);
		}
	}
}

void b_to_a(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	t_info info;

	if (len <= 3)
	{
		sorting_b(a, b, len, cmd);
		return ;
	}
	info = (t_info){0, };
	set_pivot(*b, len, 'b', &info);
	divide_b(a, b, len, &info, cmd);
	a_to_b(a, b, info.cnt_pa - info.cnt_ra, cmd);
	both_rroll(a, b, info.cnt_ra, cmd);
	a_to_b(a, b, info.cnt_ra, cmd);
	b_to_a(a, b, info.cnt_rb, cmd);
}