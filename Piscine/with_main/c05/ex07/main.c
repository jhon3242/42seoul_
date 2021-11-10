/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:16:42 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/18 19:50:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	tmp;

	tmp = nb;
	while (!is_prime(tmp))
		tmp++;
	return (tmp);
}

int main()
{
	int	i;

	i = 0;
	while (i < 100)
	{
		printf("%d %d\n",i,ft_find_next_prime(i));
		i++;
	}
}
