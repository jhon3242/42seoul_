/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:52:01 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/11 14:22:49 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

time_t	get_cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

time_t	get_diff_time(time_t start_time)
{
	return (get_cur_time() - start_time);
}

void	print_log(t_philo *philo, enum e_log_type type)
{
	time_t			time_stamp;
	unsigned int	id;

	time_stamp = get_diff_time(philo->info->start_time);
	id = philo->id;
	sem_wait(philo->shared->end_key);
	if (type == FORK)
		printf(C_GREN "%ld %u has taken a fork\n" C_RESET, time_stamp, id);
	else if (type == EAT)
		printf(C_YLLW "%ld %u is eating\n" C_RESET, time_stamp, id);
	else if (type == SLEEP)
		printf(C_BLUE "%ld %u is sleeping\n" C_RESET, time_stamp, id);
	else if (type == THINK)
		printf(C_RED "%ld %u is thinking\n" C_RESET, time_stamp, id);
	sem_post(philo->shared->end_key);
}
