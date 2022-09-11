/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:33:24 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/11 15:24:11 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	close_semaphore(t_shared *shared, t_info *info)
{
	unsigned int	i;

	if (shared->forks != 0)
		sem_close(shared->forks);
	if (shared->forks_key != 0)
		sem_close(shared->forks_key);
	if (shared->end_key != 0)
		sem_close(shared->end_key);
	if (shared->full_philos != 0)
		sem_close(shared->full_philos);
	if (shared->forks != 0)
		sem_close(shared->forks);
	i = 1;
	while (i <= info->phc)
	{
		if (shared->event_key[i] != 0)
			sem_close(shared->event_key[i]);
		i++;
	}
}

static void	unlink_semaphore(t_shared *shared, t_info *info)
{
	unsigned int	i;

	if (shared->forks != 0)
		sem_unlink("forks");
	if (shared->forks_key != 0)
		sem_unlink("forks_key");
	if (shared->end_key != 0)
		sem_unlink("end_key");
	if (shared->full_philos != 0)
		sem_unlink("full_philos");
	i = 1;
	while (i <= info->phc)
	{
		if (shared->event_key[i] != 0)
			sem_close(shared->event_key[i]);
		i++;
	}
}

int	open_semaphore(const char *name, unsigned int size, sem_t **sem_out)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT | O_EXCL, 0644, size);
	if (sem == SEM_FAILED)
		return (1);
	*sem_out = sem;
	return (0);
}

int	destory_semaphore(t_shared *shared, t_info *info)
{
	close_semaphore(shared, info);
	unlink_semaphore(shared, info);
	return (1);
}

int	init_semaphore(t_shared *shared, t_info *info)
{
	unsigned int	i;
	char			sem_name[21];

	memset(shared, 0, sizeof(t_shared));
	if (open_semaphore("forks_key", info->phc / 2, &(shared->forks_key)))
		return (destory_semaphore(shared, info));
	if (open_semaphore("forks", info->phc, &(shared->forks)))
		return (destory_semaphore(shared, info));
	if (open_semaphore("end_key", 1, &(shared->end_key)))
		return (destory_semaphore(shared, info));
	if (open_semaphore("full_philos", 0, &(shared->full_philos)))
		return (destory_semaphore(shared, info));
	shared->event_key = (sem_t **)malloc(sizeof(sem_t) * (info->phc + 1));
	if (shared->event_key == NULL)
		return (1);
	i = 1;
	while (i <= info->phc)
	{
		set_sem_name(sem_name, i);
		if (open_semaphore(sem_name, 1, &(shared->event_key[i])))
			return (destory_semaphore(shared, info));
		i++;
	}
	return (0);
}
