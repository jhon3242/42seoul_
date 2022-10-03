/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:38:12 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/08 17:47:20 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define CONTEXT_SWITCHING_TIME 1000

# define C_RED		"\033[1;31m"
# define C_GREN		"\033[1;32m"
# define C_YLLW		"\033[1;33m"
# define C_BLUE		"\033[1;34m"
# define C_PRPL		"\033[0;35m"
# define C_RESET	"\033[0m"

enum e_exit
{
	SUCCESS,
	PARSE_FAIL,
	MALLOC_FAIL,
	MUTEX_FAIL,
	RUNTIME_FAIL
};

enum e_log_type
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD,
};

typedef struct s_info
{
	unsigned int	phc;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	npe;
	time_t			start_time;
}				t_info;

typedef struct s_mutex
{
	pthread_mutex_t	mutex_lock;
	int				is_end;
}				t_mutex;

typedef struct s_philo
{
	pthread_t		thread;
	time_t			last_eating_time;
	unsigned int	id;
	unsigned int	eat_count;
	pthread_mutex_t	event_lock;
	pthread_mutex_t	fork;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_info			*info;
	t_mutex			*mutex;
}				t_philo;

/* initialize.c
## =====================================================
*/
int		malloc_t_philo(t_philo **philos, t_info *info);
void	init_philos(t_philo *philos, t_info *info, t_mutex *mutex);

/* mutex.c
## =====================================================
*/
int		init_mutex(t_philo *philos, t_info *info, t_mutex *mutex);
void	destory_mutex(t_philo *philos);

/* observe.c
## =====================================================
*/
void	*observe_philos(void *_philos);

/* parsing.c
## =====================================================
*/
int		parsing_argv(t_info *info, int argc, char *argv[]);

/* routine_util.c
## =====================================================
*/
void	get_forks(t_philo *philo);
void	return_fork(t_philo *philo);
void	automic_sleep(time_t time_to_wait);

/* routine.c
## =====================================================
*/
void	*do_routine(void *_philo);

/* running.c
## =====================================================
*/
void	stop_running(t_philo *philo);
int		is_end_running(t_philo *philo);
int		running(t_philo *philos, t_info *info);

/* util.c
## =====================================================
*/
size_t	ft_strlen(const char *str);
time_t	get_cur_time(void);
time_t	get_diff_time(time_t start_time);
void	print_log(t_philo *philo, enum e_log_type type);

#endif