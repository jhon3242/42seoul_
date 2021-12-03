/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:19:06 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/12/03 01:53:39 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*re;
	t_list	*cur;
	t_list	*tmp;

	re = 0;
	if (!lst || !f || !del)
		return (0);
	re = ft_lstnew(f(lst->content));
	if (re == 0)
		return (0);
	cur = re;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == 0)
		{
			ft_lstclear(&re, del);
			return (0);
		}
		cur->next = tmp;
		cur = cur->next;
		lst = lst->next;
	}
	return (re);
}
