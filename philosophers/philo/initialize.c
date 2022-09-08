/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:11:12 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/08 17:12:45 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_t_philo(t_philo **philos, t_info *info)
{
	*philos = malloc(sizeof(t_philo) * info->phc);
	if (*philos == NULL)
		return (1);
	return (0);
}

void	init_philos(t_philo *philos, t_info *info, t_mutex *mutex)
{
	unsigned int	i;

	mutex->is_end = 0;
	i = 0;
	while (i < info->phc)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].lfork = &(philos[i].fork);
		philos[i].rfork = &(philos[(i + 1) % info->phc].fork);
		philos[i].info = info;
		philos[i].mutex = mutex;
		i++;
	}
}
