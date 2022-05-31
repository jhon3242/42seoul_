/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:22:54 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/05/31 17:59:40 by wonjchoi         ###   ########.fr       */
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