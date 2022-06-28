/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:07:17 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/28 18:14:25 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	both_op(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "ss\n", 3))
	{
		op_swap(*a);
		op_swap(*b);
	}
	else if (!ft_strncmp(op, "rr\n", 3))
	{
		 op_roll(a);
		 op_roll(b);
	}
	else if (!ft_strncmp(op, "rrr\n", 4))
	{
		op_rroll(a);
		op_rroll(b);
	}
}

static void	run_op(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		op_swap(*a);
	else if (!ft_strncmp(op, "sb\n", 3))
		op_swap(*b);
	else if (!ft_strncmp(op, "ss\n", 3))
		both_op(a, b, op);
	else if (!ft_strncmp(op, "pa\n", 3))
		push_node(a, pop_node(b));
	else if (!ft_strncmp(op, "pb\n", 3))
		push_node(b, pop_node(a));
	else if (!ft_strncmp(op, "ra\n", 3))
		op_roll(a);
	else if (!ft_strncmp(op, "rb\n", 3))
		op_roll(b);
	else if (!ft_strncmp(op, "rr\n", 3))
		both_op(a, b, op);
	else if (!ft_strncmp(op, "rra\n", 4))
		op_rroll(a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		op_rroll(b);
	else if (!ft_strncmp(op, "rrr\n", 4))
		both_op(a, b, op);
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
