/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_add.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 23:07:40 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_command(t_cmd **cmd, char *op)
{
	t_cmd	*tmp;

	tmp = create_cmd(op);
	append_new_cmd(cmd, tmp);
}

void	do_command(t_stack **a, t_stack **b, t_cmd **cmd)
{
	t_cmd	*head;
	t_cmd	*tmp;

	head = *cmd;
	tmp = *cmd;
	do_op(tmp->cmd, a, b, cmd);
	tmp = tmp->nxt;
	while (tmp != head)
	{
		do_op(tmp->cmd, a, b, cmd);
		tmp = tmp->nxt;
	}
}
