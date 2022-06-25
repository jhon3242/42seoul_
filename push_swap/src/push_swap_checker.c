/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:07:17 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/26 01:14:19 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	run_op(t_stack **a, t_stack **b, char *op)
{
	printf("###%s###\n", op);
	if (!ft_strcmp(op, "sa"))
		op_swap(*a);
	else if (!ft_strcmp(op, "sb"))
		op_swap(*b);
	else if (!ft_strcmp(op, "ss") && op_swap(*a))
		op_swap(*b);
	else if (!ft_strcmp(op, "pa"))
		push_node(a, pop_node(b));
	else if (!ft_strcmp(op, "pb"))
		push_node(b, pop_node(a));
	else if (!ft_strcmp(op, "ra"))
		op_roll(a);
	else if (!ft_strcmp(op, "rb"))
		op_roll(b);
	else if (!ft_strcmp(op, "rr") && op_roll(a))
		op_roll(b);
	else if (!ft_strcmp(op, "rra"))
		op_rroll(a);
	else if (!ft_strcmp(op, "rrb"))
		op_rroll(b);
	else if (!ft_strcmp(op, "rrr") && op_rroll(a))
		op_rroll(b);
	else
		print_error();
}

static void	checker(t_stack **a, t_stack **b)
{
	char	*op;

	op = 0;
	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		run_op(a, b, op);
		free(op);
	}
}

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*a;
	t_stack	*b;
	t_cmd	*cmd;

	if (ac < 2)
		return (0);
	line = get_line_num(ac, av);
	init_stack(line, &a, &b, &cmd);
	check_same_value(a);
	checker(&a, &b);
	if (get_stack_len(b) == 0 && is_accend(a, get_stack_len(a)))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	exit(0);
	return (0);
}
