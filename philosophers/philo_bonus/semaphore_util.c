/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:42:14 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/09 17:06:07 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_sem_name(char *name_arr, unsigned int id)
{
	const char		*suffix = "event_lock";
	unsigned int	tmp;
	int				len;
	int				i;

	tmp = id;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	i = len;
	while (i >= 0)
	{
		name_arr[--i] = (id % 10) + '0';
		id /= 10;
	}
	i = 0;
	while (suffix[i])
	{
		name_arr[len + i] = suffix[i];
		i++;
	}
	name_arr[len + i] = '\0';
}