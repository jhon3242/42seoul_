/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:35:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/24 20:15:28 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_stack(char **av, t_stack **a, t_stack**b, t_command **cmd)
{
	int		tmp_num;
	t_stack	*new_node;

	*a = 0;
	*b = 0;
	*cmd = 0;
	while (*av)
	{
		tmp_num = atoi_and_nullck(*av);
		new_node = create_node(tmp_num);
		append_new_node(a, new_node);
		av++;
	}
}

static void check_same_value(t_stack *a)
{
	t_stack *tail;
	t_stack *now;

	tail = a->prv;
	now = a->nxt;
	while (1)
	{
		if (a == tail)
			break;
		while (1)
		{
			if (now == tail->nxt)
				break;
			if (a->val == now->val)
				print_error();
			now = now->nxt;
		}
		a = a->nxt;
		now = a->nxt;
	}
}

void print_error()
{
	write(2, "Error\n", 6);
	exit(1);
}

int main(int ac, char **av)
{
	int		len;
	t_stack	*a;
	t_stack	*b;
	t_cmd *cmd;

	if (ac < 2)
		return (0);
	++av;
	len = get_len(av);
	init_stack(av, &a, &b, &cmd);
	check_same_value(a);
	if (len >= 2 && is_decend(a, len))
		reverse_stack(&a, &b, len);
	else if (len >= 3 && !is_accend(a, len))
		sort_by_len(&a, &b, len, &cmd);
	exit(0);
	return (0);
}