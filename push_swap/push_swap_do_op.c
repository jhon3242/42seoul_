/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_do_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:37:54 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 17:55:58 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int op_swap(t_stack *a)
{
	int	tmp;

	tmp = a->val;
	a->val = a->nxt->val;
	a->nxt->val = tmp;
	return (1);
}

static int op_roll(t_stack **a)
{
	*a = (*a)->nxt;
	return (1);
}

static int op_rroll(t_stack **a)
{
	*a = (*a)->prv;
	return (1);
}


void do_op(char	*op, t_stack **a, t_stack **b, t_cmd **cmd)
{
	if (!ft_strcmp(op, "sa") && op_swap(*a))
		add_command(cmd, "sa");
	else if (!ft_strcmp(op, "sb") && op_swap(*b))
		add_command(cmd, "sb");
	else if (!ft_strcmp(op, "ss") && op_swap(*a) && op_swap(*b))
		add_command(cmd, "ss");
	else if (!ft_strcmp(op, "pa") && push_node(a, pop_node(b)))
		add_command(cmd, "pa");
	else if (!ft_strcmp(op, "pb") && push_node(b, pop_node(a)))
		add_command(cmd, "pb");
	else if (!ft_strcmp(op, "ra") && op_roll(a))
		add_command(cmd, "ra");
	else if (!ft_strcmp(op, "rb") && op_roll(b))
		add_command(cmd, "rb");
	else if (!ft_strcmp(op, "rr") && op_roll(a) && op_roll(b))
		add_command(cmd, "rr");
	else if (!ft_strcmp(op, "rra") && op_rroll(a))
		add_command(cmd, "rra");
	else if (!ft_strcmp(op, "rrb") && op_rroll(b))
		add_command(cmd, "rrb");
	else if (!ft_strcmp(op, "rrr") && op_rroll(a) && op_rroll(b))
		add_command(cmd, "rrr");
}


void both_rroll(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	while (len > 0)
	{
		do_op("rrr", a, b, cmd);
		len--;
	}
}