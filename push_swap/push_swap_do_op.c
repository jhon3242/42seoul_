/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_do_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:37:54 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/21 21:18:01 by wonjchoi         ###   ########.fr       */
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

void do_op(char	*op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "sa") && op_swap(*a))
		ft_putstr_fd("sa\n", 1);
	else if (!ft_strcmp(op, "sb") && op_swap(*b))
		ft_putstr_fd("sb\n", 1);
	else if (!ft_strcmp(op, "ss") && op_swap(*a) && op_swap(*b))
		ft_putstr_fd("ss\n", 1);
	else if (!ft_strcmp(op, "pa") && push_node(a, pop_node(b)))
		ft_putstr_fd("pa\n", 1);
	else if (!ft_strcmp(op, "pb") && push_node(b, pop_node(a)))
		ft_putstr_fd("pb\n", 1);
	else if (!ft_strcmp(op, "ra") && op_roll(a))
		ft_putstr_fd("ra\n", 1);
	else if (!ft_strcmp(op, "rb") && op_roll(b))
		ft_putstr_fd("rb\n", 1);
	else if (!ft_strcmp(op, "rr") && op_roll(a) && op_roll(b))
		ft_putstr_fd("rr\n", 1);
	else if (!ft_strcmp(op, "rra") && op_rroll(a))
		ft_putstr_fd("rra\n", 1);
	else if (!ft_strcmp(op, "rrb") && op_rroll(b))
		ft_putstr_fd("rrb\n", 1);
	else if (!ft_strcmp(op, "rrr") && op_rroll(a) && op_rroll(b))
		ft_putstr_fd("rrr\n", 1);
}

void both_rroll(t_stack **a, t_stack **b, int len)
{
	while (len > 0)
	{
		do_op("rrr", a, b);
		len--;
	}
}