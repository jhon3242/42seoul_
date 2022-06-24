/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:06:11 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/24 20:15:25 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_new_node(t_stack **a, t_stack *node)
{
	if (*a == 0)
		*a = node;
	else
	{
		(*a)->prv->nxt = node;
		node->prv = (*a)->prv;
		(*a)->prv = node;
		node->nxt = *a;
	}
}

t_stack*	create_node(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		print_error();
	new_node->val = num;
	new_node->prv = new_node;
	new_node->nxt = new_node;
	return (new_node);
}

void	append_new_cmd(t_stack **a, t_stack *node)
{
	if (*a == 0)
		*a = node;
	else
	{
		(*a)->prv->nxt = node;
		node->prv = (*a)->prv;
		(*a)->prv = node;
		node->nxt = *a;
	}
}

t_command*	create_cmd(char *cmd)
{
	t_command	*new_node;

	new_node = malloc(sizeof(t_command));
	if (!new_node)
		print_error();
	new_node->cmd = cmd;
	new_node->prv = new_node;
	new_node->nxt = new_node;
	return (new_node);
}