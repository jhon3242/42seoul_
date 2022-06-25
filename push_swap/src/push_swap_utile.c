/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:45:10 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/26 01:14:00 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(char *line, t_stack **a, t_stack**b, t_cmd **cmd)
{
	int		tmp_num;
	char	**strs;
	t_stack	*new_node;
	int		i;

	*a = 0;
	*b = 0;
	*cmd = 0;
	i = -1;
	strs = ft_split(line, ' ');
	while (strs[++i])
	{
		tmp_num = atoi_and_nullck(strs[i]);
		new_node = create_node(tmp_num);
		append_new_node(a, new_node);
		line++;
	}
}

void	check_same_value(t_stack *a)
{
	t_stack	*tail;
	t_stack	*now;

	tail = a->prv;
	now = a->nxt;
	while (1)
	{
		if (a == tail)
			break ;
		while (1)
		{
			if (now == tail->nxt)
				break ;
			if (a->val == now->val)
				print_error();
			now = now->nxt;
		}
		a = a->nxt;
		now = a->nxt;
	}
}
