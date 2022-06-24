/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_add_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/24 20:15:24 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void add_command(t_cmd **cmd, char *op)
{
	t_cmd *tmp;

	tmp = create_cmd(op);
	append_new_cmd(cmd, tmp);
}
