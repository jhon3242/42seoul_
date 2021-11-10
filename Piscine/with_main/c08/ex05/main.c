/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:04:06 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/21 14:29:22 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

extern struct s_stock_str *ft_strs_to_tab(int ac, char **av);

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int	nb)
{
	char	ch;

	if (nb >= 10)
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
	else
	{
		ch = nb + '0';
		write(1, &ch, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	ft_putstr(par->str);
	if (par->size > 0)
		ft_putnbr(par->size);
	write(1, "\n", 1);
	ft_putstr(par->copy);
}

int main()
{
	char	*ar[2];

	ar[0] = "this";
	ar[1] = "is";
	t_strock_str *ret  = ft_strs_to_tab(2, ar);
	ft_show_tab(ret);
}
