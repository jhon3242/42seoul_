/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:16:40 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/28 17:52:02 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_decend(t_stack *a, int len)
{
	while (len-- > 1)
	{
		if (a->val < a->nxt->val)
			return (0);
		a = a->nxt;
	}
	return (1);
}

int	is_accend(t_stack *a, int len)
{
	while (len-- > 1)
	{
		if (a->val > a->nxt->val)
			return (0);
		a = a->nxt;
	}
	return (1);
}

void	reverse_stack(t_stack **a, t_stack **b, int len, t_cmd **cmd)
{
	int	pb_count;

	if (len == 2)
		do_op("sa", a, b, cmd);
	else if (len == 3)
	{
		do_op("sa", a, b, cmd);
		do_op("rra", a, b, cmd);
	}
	else
	{
		pb_count = 0;
		while (pb_count < len - 1)
		{
			do_op("pb", a, b, cmd);
			pb_count++;
		}
		while (pb_count > 0)
		{
			do_op("pa", a, b, cmd);
			do_op("ra", a, b, cmd);
			pb_count--;
		}
	}
}

t_stack	*pop_node(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (!*a)
		return (0);
	if (*a == (*a)->nxt)
		*a = 0;
	else
	{
		(*a)->prv->nxt = (*a)->nxt;
		(*a)->nxt->prv = (*a)->prv;
		*a = (*a)->nxt;
		tmp->prv = tmp;
		tmp->nxt = tmp;
	}
	return (tmp);
}

int	push_node(t_stack **dst, t_stack *src)
{
	if (!src)
		return (1);
	if (*dst != 0)
	{
		(*dst)->prv->nxt = src;
		src->prv = (*dst)->prv;
		(*dst)->prv = src;
		src->nxt = *dst;
	}
	*dst = src;
	return (1);
}
