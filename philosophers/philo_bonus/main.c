/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:19:59 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/11 15:24:27 by wonjchoi         ###   ########.fr       */
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
	};

	if (exit_status == SUCCESS)
		return (SUCCESS);
	write(STDERR_FILENO, msg[exit_status], ft_strlen(msg[exit_status]));
	return (exit_status);
}

int	main(int argc, char *argv[])
{
	t_philo		philo;
	t_info		info;
	t_shared	shared;

	if (parsing_argv(&info, argc, argv))
		return (exit_with(PARSE_FAIL));
	memset(&philo, 0, sizeof(t_philo));
	philo.info = &info;
	if (init_semaphore(&shared, &info))
		return (exit_with(SEMAPHORE_FAIL));
	philo.shared = &shared;
	if (running(&philo))
	{
		destory_semaphore(&shared, &info);
		return (exit_with(RUNTIME_FAIL));
	}
	destory_semaphore(&shared, &info);
	return (exit_with(SUCCESS));
}
