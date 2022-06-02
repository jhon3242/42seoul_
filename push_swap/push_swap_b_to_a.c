/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:22:03 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/01 22:59:19 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sorting_b(t_stack **a, t_stack **b, int len)
{
	if (len == 2 || len == 3)
	{
		if ((*b)->val < (*b)->nxt->val)
			do_op("sb", a, b);
		if (len == 3)
		{
			if (!is_decend(*b, len))
			{
				do_op("rb", a, b);
				do_op("sb", a, b);
				do_op("rrb", a, b);
				if ((*b)->val < (*b)->nxt->val)
					do_op("sb", a, b);
			}
			do_op("pa", a, b);
		}
		do_op("pa", a, b);
	}
	do_op("pa", a, b);
}

static void divide_b(t_stack **a, t_stack **b, int len, t_info *info)
{
	while (len-- > 0)
	{
		if ((*b)->val >= info->pvt_greater)
		{
			do_op("pa", a, b);
			++(info->cnt_pa);
		}
		else if ((*b)->val < info->pvt_less)
		{
			do_op("rb", a, b);
			++(info->cnt_rb);
		}
		else
		{
			do_op("pa", a, b);
			do_op("ra", a, b);
			++(info->cnt_pa);
			++(info->cnt_ra);
		}
	}
}

void b_to_a(t_stack **a, t_stack **b, int len)
{
	t_info info;

	if (len <= 3)
	{
		sorting_b(a, b, len);
		return ;
	}
	info = (t_info){0, };
	set_pivot(*b, len, 'b', &info);
	divide_b(a, b, len, &info);
	a_to_b(a, b, info.cnt_pa - info.cnt_ra);
	both_rroll(a, b, info.cnt_ra);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
}