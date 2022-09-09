/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:26:34 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/09/09 18:34:05 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
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
	SEMAPHORE_FAIL,
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

typedef struct s_shared
{
	sem_t	*forks;
	sem_t	*forks_key;
	sem_t	*end_key;
	sem_t	*full_philos;
	sem_t	**event_key;
}				t_shared;

typedef struct	s_info
{
	unsigned int	phc;
	unsigned int	ttd;
	unsigned int	tte;
	unsigned int	tts;
	unsigned int	npe;
	time_t			start_time;
}				t_info;

typedef struct s_philo
{
	unsigned int	id;
	unsigned int	eat_count;
	time_t			last_eating_time;
	t_info			*info;
	t_shared		*shared;
}				t_philo;



/* parsing.c
## =====================================================
*/
int		parsing_argv(t_info *info, int argc, char *argv[]);

/* semaphore_util.c
## =====================================================
*/
void	set_sem_name(char *name_arr, unsigned int id);

/* semaphore.c
## =====================================================
*/
int	init_semaphore(t_shared *shared, t_info *info);

/* observe.c
## =====================================================
*/
void	*observe_dead(void *_philo);
int		observe_full(t_philo *philo);

/* routine_util.c
## =====================================================
*/
void	get_forks(t_philo *philo);
void	return_fork(t_philo *philo);
void	automic_sleep(time_t time_to_wait);

/* util.c
## =====================================================
*/
size_t	ft_strlen(const char *str);
time_t	get_cur_time(void);
time_t	get_diff_time(time_t start_time);
void	print_log(t_philo *philo, enum e_log_type type);

#endif