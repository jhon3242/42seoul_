/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:35:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/30 13:33:04 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;
	t_cmd	*last;

	tmp = (*cmd);
	last = (*cmd);
	ft_printf("%s\n", tmp->cmd);
	tmp = tmp->nxt;
	free(last);
	while (tmp != (*cmd))
	{
		ft_printf("%s\n", tmp->cmd);
		last = tmp;
		tmp = tmp->nxt;
		free(last);
	}
}

int	main(int ac, char **av)
{
	int		len;
	char	*line;
	t_stack	*a;
	t_stack	*b;
	t_cmd	*cmd;

	if (ac < 2)
		return (0);
	len = get_len(av) - 1;
	line = get_line_num(ac, av);
	init_stack(line, &a, &b, &cmd);
	check_same_value(a);
	if (len >= 2 && is_decend(a, len))
		reverse_stack(&a, &b, len, &cmd);
	else if (len >= 3 && !is_accend(a, len))
		sort_by_len(&a, &b, len, &cmd);
	if (cmd)
		zip_command(&cmd);
	if (cmd)
		print_cmd(&cmd);
	clear_lst(a);
	exit(0);
	return (0);
}
