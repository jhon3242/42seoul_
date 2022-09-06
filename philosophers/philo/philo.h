/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:38:12 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/06 20:23:02 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
// #include <unistd.h>

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

/* parsing.c
## =====================================================
*/
int	parsing_argv(t_info *info, int argc, char *argv[]);

/* util.c
## =====================================================
*/
size_t	ft_strlen(const char *str);

#endif

