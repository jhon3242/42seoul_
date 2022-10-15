/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:16:40 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/10/16 00:49:13 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_decend(t_stack *a, int len)
{
	while (len-- > 1)
	{
		if (a->val < a->prev->val)
			return (0);
		a = a->prev;
	}
	return (1);
}

int	is_accend(t_stack *a, int len)
{
	while (len-- > 1)
	{
		if (a->val > a->prev->val)
			return (0);
		a = a->prev;
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
	if (*a == (*a)->prev)
		*a = 0;
	else
	{
		(*a)->next->prev = (*a)->prev;
		(*a)->prev->next = (*a)->next;
		*a = (*a)->prev;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	return (tmp);
}

int	push_node(t_stack **dst, t_stack *src)
{
	if (!src)
		return (1);
	if (*dst != 0)
	{
		(*dst)->next->prev = src;
		src->next = (*dst)->next;
		(*dst)->next = src;
		src->prev = *dst;
	}
	*dst = src;
	return (1);
}
