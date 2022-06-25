/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_command_zip.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:57:29 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/06/25 23:16:43 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_node(t_cmd *tmp)
{
	if (!tmp)
		return ;
	tmp->cmd = 0;
	tmp->nxt = 0;
	tmp->prv = 0;
	free(tmp);
}

static t_cmd	*delete_both(t_cmd *f, t_cmd *s, t_cmd **head)
{
	t_cmd	*a;
	t_cmd	*b;

	a = f->prv;
	b = s->nxt;
	if (f == (*head))
		*head = a;
	if (a->nxt == b && b->nxt == a)
		*head = 0;
	else
	{
		a->nxt = b;
		b->prv = a;
	}
	free_node(f);
	free_node(s);
	return (a);
}

static const char	*can_zip(t_cmd *f, t_cmd *s)
{
	if (!ft_strcmp(f->cmd, "pa") && !ft_strcmp(s->cmd, "pb"))
		return ("remove");
	else if (!ft_strcmp(f->cmd, "pb") && !ft_strcmp(s->cmd, "pa"))
		return ("remove");
	else if (!ft_strcmp(f->cmd, "ra") && !ft_strcmp(s->cmd, "rb"))
		return ("rr");
	else if (!ft_strcmp(f->cmd, "rb") && !ft_strcmp(s->cmd, "ra"))
		return ("rr");
	else if (!ft_strcmp(f->cmd, "rra") && !ft_strcmp(s->cmd, "rrb"))
		return ("rrr");
	else if (!ft_strcmp(f->cmd, "rrb") && !ft_strcmp(s->cmd, "rra"))
		return ("rrr");
	else if (!ft_strcmp(f->cmd, "sa") && !ft_strcmp(s->cmd, "sb"))
		return ("ss");
	else if (!ft_strcmp(f->cmd, "sb") && !ft_strcmp(s->cmd, "sa"))
		return ("ss");
	else
		return ("nothing");
}

static t_cmd	*new_command(t_cmd *f, t_cmd *s, char *cmd)
{
	f->cmd = cmd;
	f->nxt = s->nxt;
	s->nxt->prv = f;
	free(s);
	return (f);
}

void	zip_command(t_cmd **head)
{
	t_cmd	*f;
	t_cmd	*s;
	char	*new_cmd;

	f = (*head);
	s = (*head)->nxt;
	if (!s || !f)
		return ;
	while (s != (*head) && s != f)
	{
		new_cmd = (char *)can_zip(f, s);
		if (ft_strcmp(new_cmd, "nothing"))
		{
			if (!ft_strcmp(new_cmd, "remove"))
				f = delete_both(f, s, head);
			else
				f = new_command(f, s, new_cmd);
			s = f->nxt;
			continue ;
		}
		f = s;
		s = s->nxt;
	}
	if (f == s && !(f->cmd))
		*head = 0;
}
