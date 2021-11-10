#include <unistd.h>

extern void ft_putnbr(char c);
extern void ft_putstr(char *str);

void	ft_sum(int n1, int n2)
{
	ft_putnbr(n1 + n2);
}

void	ft_min(int n1, int n2)
{
	ft_putnbr(n1 - n2);
}

void	ft_mul(int n1, int n2)
{
	ft_putnbr(n1 * n2);
}

void	ft_div(int n1, int n2)
{
	if (n2 == 0)
	{
		ft_putstr("Stop : division by zero");
		return ;
	}
	ft_putnbr(n1 / n2);
}

void	ft_mod(int n1, int n2)
{
	if (n2 == 0)
	{
		ft_putstr("Stop : modulo by zero");
		return ;
	}
	ft_putnbr(n1 % n2);
}

