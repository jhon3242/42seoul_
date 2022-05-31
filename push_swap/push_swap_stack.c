/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:16:40 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/05/31 20:20:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_decend(t_stack *a, int len)
{
	while (len-- > 1)
	{
		if (a->val < a->nxt->val)
			return (0);
		a = a->nxt;
	}
	return (1);
}

int is_accend(t_stack *a, int len)
{
	while (len-- > 1)
	{
		if (a->val > a->nxt->val)
			return (0);
		a = a->nxt;
	}
	return (1);
}