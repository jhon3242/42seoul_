#include <unistd.h>

int	ft_atoi(char *str)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret);
}

void	ft_putnbr(int nb)
{
	char c;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}


void	ft_op(char *str)
{
	int nb;
	char	x;

	nb = ft_atoi(str);
	x = 0;
	while (++x <= 9)
	{
		ft_putnbr(x);
		write(1, " x ", 3);
		ft_putnbr(nb);
		write(1, " = ", 3);
		ft_putnbr(x * nb);
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 1)
		while (++i < ac)
			ft_op(av[i]);
	else
		write(1, "\n", 1);
}
