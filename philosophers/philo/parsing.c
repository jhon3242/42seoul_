/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <choewonjun@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:24:37 by choewonjun        #+#    #+#             */
/*   Updated: 2022/09/06 20:34:03 by choewonjun       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str || *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		if (ret < 0)
			return ((sign + 1) / -2);
		str++;
	}
	return (ret * sign);
}

static int	check_argv(int argc, char *argv[])
{
	int	i;
	int	j;
	long long result;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	result = 0;
	while (i < argc)
	{
		j = 0;
		while ('0' <= argv[i][j] && argv[i][j] <= '9')
		{
			result = result * 10 + (argv[i][j] - '0');
			if (result > INT_MAX)
				return (1);
			j++;
		}
		if (argv[i][j] != '\0' || result == 0)
			return (1);
		i++;
	}
	return (0);
}

int	parsing_argv(t_info *info, int argc, char *argv[])
{
	if (check_argv(argc, argv))
		return (1);
	memset(info, 0, sizeof(t_info));
	info->phc = ft_atoi(argv[1]);
	info->ttd = ft_atoi(argv[2]);
	info->tte = ft_atoi(argv[3]);
	info->tts = ft_atoi(argv[4]);
	if (argc == 6)
		info->npe = ft_atoi(argv[5]);
	return (0);
}
