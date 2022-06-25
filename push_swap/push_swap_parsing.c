/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:22:54 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 21:41:39 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_len(char **av)
{
	int		len;
	char	*tmp;

	len = 0;
	while (*av)
	{
		if (**av == 0)
			print_error();
		tmp = *av;
		while (*tmp)
		{
			while (*tmp && *tmp == ' ')
				tmp++;
			if (*tmp && *tmp != ' ')
				len++;
			while (*tmp && *tmp != ' ')
				tmp++;
		}
		av++;
	}
	return (len);
}

char	*get_line_num(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*line;

	i = 1;
	tmp = 0;
	line = 0;
	while (i < argc)
	{
		if (*argv[i] == 0)
			print_error();
		tmp = ft_strjoin(line, argv[i]);
		if (!tmp)
			print_error();
		free(line);
		line = tmp;
		tmp = ft_strjoin(line, " ");
		if (!tmp)
			print_error();
		free(line);
		line = tmp;
		++i;
	}
	return (line);
}