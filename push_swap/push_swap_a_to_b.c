/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:47:47 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/24 20:15:23 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sorting_a(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	if (len == 2 || len == 3)
	{
		if ((*a)->val > (*a)->nxt->val)
			add_command(cmd, "sa");
		if (len == 3 && !is_accend(*a, len))
		{
			add_command(cmd, "ra");
			
			add_command(cmd, "sa");
			add_command(cmd, "rra");
			if ((*a)->val > (*a)->nxt->val)
				add_command(cmd, "sa");
		}
	}
}

static void divide_a(t_stack **a, t_stack **b, int len, t_info *i, t_cmd **t)
{
	while (len-- > 0)
	{
		if ((*a)->val > i->pvt_greater)
		{
			add_command(t, "ra");
			(i->cnt_ra)++;
		}
		else if ((*a)->val <= i->pvt_less)
		{
			add_command(t, "pb");
			(i->cnt_pb)++;
		}
		else
		{
			add_command(t, "pb");
			add_command(t, "rb");
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
	divide_a(a, b, len, &info);
	both_rroll(a, b, info.cnt_rb);
	a_to_b(a, b, info.cnt_ra);
	b_to_a(a, b, info.cnt_rb);
	b_to_a(a, b, info.cnt_pb - info.cnt_rb);
}