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

void	print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	n = n % 16;
	if (n >= 10)
		n = n + 'a' - 10;
	else
		n = n + '0';
	write(1, &n, 1);
}

void	ft_op(char *str)
{
	int	nb;

	nb = ft_atoi(str);
	print_hex(nb);
}


int main(int ac, char **av)
{
	if (ac == 2)
		ft_op(av[1]);
	write(1, "\n", 1);
}
