/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:45:22 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/07 13:37:42 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	oadd(t_object **list, t_object *new_obj)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new_obj;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new_obj;
}

t_object	*object(void *object, int type)
{
	t_object	*new;

	new = ft_malloc(sizeof(t_object));
	new->element = object;
	new->next = NULL;
	new->type = type;
	return (new);
}
