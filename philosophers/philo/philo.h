/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:38:12 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/07 16:16:51 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

# define INT_MAX 2147483647

enum e_exit
{
	SUCCESS,
	PARSE_FAIL,
	MALLOC_FAIL,
	MUTEX_FAIL,
	RUNTIME_FAIL
};

typedef struct s_info
{
	unsigned int phc;
	unsigned int ttd;
	unsigned int tte;
	unsigned int tts;
	unsigned int npe;
}				t_info;

typedef struct	s_mutex
{
	pthread_mutex_t	mutex_lock;
	int				is_end;
}				t_mutex;


typedef struct	s_philo
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	eat_count;
	pthread_mutex_t	event_lock;
	pthread_mutex_t	fork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_info			*info;
	t_mutex			*mutex;
}				t_philo;



/* parsing.c
## =====================================================
*/
int		parsing_argv(t_info *info, int argc, char *argv[]);

/* util.c
## =====================================================
*/
size_t	ft_strlen(const char *str);

/* initialize.c
## =====================================================
*/
int		malloc_t_philo(t_philo **philos, t_info *info);
void	init_philos(t_philo *philos, t_info *info, t_mutex *mutex);
int		init_mutex(t_philo *philos, t_info *info, t_mutex *mutex);

#endif

