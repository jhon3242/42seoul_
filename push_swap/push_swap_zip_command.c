/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_zip_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/24 20:15:28 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_cmd* delete_both(t_cmd *f, t_cmd *s)
{
	t_cmd *a;
	t_cmd *b;
	
	a = f->prv;
	b = s->nxt;
	a->nxt = b;
	b->prv = a;
	free(f);
	free(s);
	return a;
}

static const char *can_zip(t_cmd *f, t_cmd *s)
{
	if (ft_strcmp(f->cmd, "pa") && ft_strcmp(s->cmd, "pb"))
		return "remove";
	else if (ft_strcmp(f->cmd, "pb") && ft_strcmp(s->cmd, "pa"))
		return "remove";
	else if (ft_strcmp(f->cmd, "ra") && ft_strcmp(s->cmd, "rb"))
		return "rr";
	else if (ft_strcmp(f->cmd, "rb") && ft_strcmp(s->cmd, "ra"))
		return "rr";
	else if (ft_strcmp(f->cmd, "rra") && ft_strcmp(s->cmd, "rrb"))
		return "rrr";
	else if (ft_strcmp(f->cmd, "rrb") && ft_strcmp(s->cmd, "rra"))
		return "rrr";
	else if (ft_strcmp(f->cmd, "sa") && ft_strcmp(s->cmd, "sb"))
		return "ss";
	else if (ft_strcmp(f->cmd, "sb") && ft_strcmp(s->cmd, "sa"))
		return "ss";
	else
		return "noting"
}
static t_cmd *new_command(t_cmd *f, t_cmd *s, char *cmd)
{
	f->cmd = cmd;
	f->nxt = s->nxt;
	s->nxt->prv = f;
	free(s);
	return (f);
} 

void zip_command(t_cmd **head, int size)
{
	t_cmd	*f;
	t_cmd	*s;
	t_cmd	*ck;
	char		*tmp;

	ck = (*head);
	f = (*head);
	s = (*head)->nxt;
	if (!s || !f)
		return;
	while (s != ck)
	{
		tmp = (char *)can_zip(f, s);
		if (ft_strcmp(tmp, "nothing"))
		{
			if (ft_strcmp(tmp, "remove");
				f = delete_both(f, s);
			else
				f = new_command(f, s);
			s = f->nxt;
			continue;
		}
		f = s;
		s = s->nxt;
	}
}
