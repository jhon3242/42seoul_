/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:23:13 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/06 20:36:21 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static enum e_exit exit_with(enum e_exit exit_status)
{
	const char* msg[] = \
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

int main(int argc, char *argv[])
{
	t_info info;

	if (parsing_argv(&info, argc, argv))
		return (exit_with(PARSE_FAIL));
	
}