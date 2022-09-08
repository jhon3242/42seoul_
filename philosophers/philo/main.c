/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:13 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/08 17:45:41 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static enum	e_exit	exit_with(enum e_exit exit_status)
{
	const char	*msg[] = \
	{
		"",
		"Input must be like './philo phc ttd tte tts (npe)'\n",
		"Error : Failed to malloc\n",
		"Error : Failed to init mutex\n",
		"Error : Runtime Error\n"
	};

	if (exit_status == SUCCESS)
		return (SUCCESS);
	write(STDERR_FILENO, msg[exit_status], ft_strlen(msg[exit_status]));
	return (exit_status);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philos;
	t_mutex	mutex;

	if (parsing_argv(&info, argc, argv))
		return (exit_with(PARSE_FAIL));
	if (malloc_t_philo(&philos, &info))
		return (exit_with(MALLOC_FAIL));
	init_philos(philos, &info, &mutex);
	if (init_mutex(philos, &info, &mutex))
	{
		free(philos);
		return (exit_with(MUTEX_FAIL));
	}
	if (running(philos, &info))
	{
		free(philos);
		destory_mutex(philos);
		return (RUNTIME_FAIL);
	}
	free(philos);
	destory_mutex(philos);
	return (exit_with(SUCCESS));
}
