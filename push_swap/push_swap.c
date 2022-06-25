/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:35:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 21:52:33 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_stack(char *line, t_stack **a, t_stack**b, t_cmd **cmd)
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

static void print_cmd(t_cmd **cmd)
{
	t_cmd *tmp;

	tmp = (*cmd);
	printf("%s\n", tmp->cmd);
	tmp = tmp->nxt;
	while (tmp != (*cmd))
	{
		printf("%s\n", tmp->cmd);
		tmp = tmp->nxt;
	}
}

int main(int ac, char **av)
{
	int		len;
	char	*line;
	t_stack	*a;
	t_stack	*b;
	t_cmd *cmd;

	if (ac < 2)
		return (0);
	len = get_len(av) - 1;
	// printf("@%d\n", len);
	line = get_line_num(ac, av);
	// printf("@\n");
	init_stack(line, &a, &b, &cmd);
	check_same_value(a);
	// printf("@\n");
	if (len >= 2 && is_decend(a, len))
		reverse_stack(&a, &b, len, &cmd);
	else if (len >= 3 && !is_accend(a, len))
		sort_by_len(&a, &b, len, &cmd);
	// printf("@\n");
	if (cmd)
		zip_command(&cmd);
	if (cmd)
		print_cmd(&cmd);	
	// printf("@\n");
	exit(0);
	return (0);
}