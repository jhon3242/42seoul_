#include <unistd.h>

int	ft_atoi(char *str)
{
	int	ret;
	int sign;

	ret = 0;
	sign = 1;
	if (*str == '-')
		sign *= -1;
	while (*str)
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (sign * ret);
}

int ct(int nb)
{
	int	ret;

	ret = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 16;
		ret++;
	}
	return (ret);
}


void	ft_op(char *str)
{
	int	nb;
	int len;
	char hex[] = "0123456789abcdef";
	int result[100];
	int i;

	i = 0;
	nb = ft_atoi(str);
	len = ct(nb);
	int lend = len;
	while (len--)
	{
		result[len] = hex[nb % 16];
		nb /= 16;
	}
	while(lend--)
	{
		write(1, &result[lend], 1);
	}
}


int main(int ac, char **av)
{
	if (ac == 2)
		ft_op(av[1]);
	write(1, "\n", 1);
}
