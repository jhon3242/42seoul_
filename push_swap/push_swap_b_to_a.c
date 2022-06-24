/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:22:03 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/24 20:15:25 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sorting_b(t_stack **a, t_stack **b, int len, t_cmd ** cmd)
{
	if (len == 2 || len == 3)
	{
		if ((*b)->val < (*b)->nxt->val)
			add_command(cmd, "sb");
		if (len == 3)
		{
			if (!is_decend(*b, len))
			{
				add_command(cmd, "rb");
				add_command(cmd, "sb");
				add_command(cmd, "rrb");
				if ((*b)->val < (*b)->nxt->val)
					add_command(cmd, "sb");
			}
			add_command(cmd, "pa");
		}
		add_command(cmd, "pa");
	}
	add_command(cmd, "pa");
}

static void divide_b(t_stack **a, t_stack **b, int len, t_info *i, t_cmd **t)
{
	while (len-- > 0)
	{
		if ((*b)->val >= info->pvt_greater)
		{
			add_command(t, "pa");
			++(info->cnt_pa);
		}
		else if ((*b)->val < info->pvt_less)
		{
			add_command(t, "rb");
			++(info->cnt_rb);
		}
		else
		{
			add_command(t, "pa");
			add_command(t, "ra");
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