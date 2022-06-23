/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:47:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/23 22:07:27 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sorting_a(t_stack **a, t_stack **b, int len)
{
	
	if (len == 2 || len == 3)
	{
		if ((*a)->val > (*a)->nxt->val)
			do_op("sa", a, b);
		if (len == 3 && !is_accend(*a, len))
		{
			do_op("ra", a, b);
			do_op("sa", a, b);
			do_op("rra", a, b);
			if ((*a)->val > (*a)->nxt->val)
				do_op("sa", a, b);
		}
	}
	// else if (len == 4)
	// 	sort_4(a, b);
		
	// else if (len == 5)
	// 	sort_5(a, b);
		
}

static void divide_a(t_stack **a, t_stack **b, int len, t_info *info)
{
	while (len-- > 0)
	{
		if ((*a)->val > info->pvt_greater)
		{
			do_op("ra", a, b);
			(info->cnt_ra)++;
		}
		else if ((*a)->val <= info->pvt_less)
		{
			do_op("pb", a, b);
			(info->cnt_pb)++;
		}
		else
		{
			do_op("pb", a, b);
			do_op("rb", a, b);
			(info->cnt_pb)++;
			(info->cnt_rb)++;
		}
	}
}

void	a_to_b(t_stack **a, t_stack **b, int len)
{
	t_info info;

	if (len <= 3)
	{
		if (!is_accend(*a, len))
			sorting_a(a, b, len);
		return ;
	}
	info = (t_info){0, };
	set_pivot(*a, len, 'a', &info);
	divide_a(a, b, len, &info);
	both_rroll(a, b, info.cnt_rb);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
	b_to_a(a, b, info.cnt_pb - info.cnt_rb);
}