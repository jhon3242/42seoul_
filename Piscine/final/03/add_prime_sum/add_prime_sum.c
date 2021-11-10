#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	ret;
	int	i;
	int len;

	len = 0;
	while (str[len])
		len++;
	ret = 0;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			return (-1);
		i++;
	}
	while (i < len)
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	return (ret);
}

int	ft_sqrt(int nb)
{
	long long	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			break ;
		i++;
	}
	return (i);
}

int	is_prime(int nb)
{
	int	i;
	int max;
	
	if (nb < 2)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	max = ft_sqrt(nb);
	i = 2;
	while (i <= max)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr(int nb)
{
	char	t;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	t = nb % 10 + '0';
	write(1, &t, 1);
}

void	ft_op(char *str)
{
	int	nb;
	int	ret;

	nb = ft_atoi(str);
	if (nb < 0)
	{
		write(1, "0", 1);
		return ;
	}
	ret = 0;
	while (nb > 1)
	{
		if (is_prime(nb))
			ret += nb;
	./.	nb--;
	}
	ft_putnbr(ret);
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_op(av[1]);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
