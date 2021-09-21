#include <unistd.h>
#include "ft_stock_str.h"

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
		write(1, &ch , 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	char	tmp;
	ft_putstr(par->str);
	if (par->size > 0)
		ft_putnbr(par->size);
	write(1, "\n", 1);
	ft_putstr(par->copy);
}
