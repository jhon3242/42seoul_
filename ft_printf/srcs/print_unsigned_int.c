/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 19:34:50 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/01/30 17:11:06 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	u_num_len(unsigned int n)
{
	int	ret;

	ret = 0;
	while (n != 0)
	{
		n /= 10;
		ret ++;
	}
	return (ret);
}

int ft_unsigned_int(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n == 0)
		ret = write(1, "0", 1);
	else
	{
		ret = u_num_len(n);
		if (n >= 10)
			ft_putnbr_fd(n / 10, 1);	// int 최대 범위를 넘었을 수 있기 때문에 나눠서 출력
		ft_putnbr_fd(n % 10, 1);
	}
	return (ret);
}