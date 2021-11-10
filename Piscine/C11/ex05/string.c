#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		else
		{
			write(1, "-", 1);
			n *= -1;
		}
	}
	if (n > 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}	

int		ft_atoi(char *str)
{
	int ret;
	int sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		ret *= 10;
		ret += (sign * (*(str++) - '0'));
	}
	return (ret);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
