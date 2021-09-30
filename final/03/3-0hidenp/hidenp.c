#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	c = nb + '0';
	write(1, &c, 1);
}

int	ft_op(char *st1, char *st2)
{
	int	i;

	i = 1;
	while (*st1)
	{
		while (st2[i] && *st1 != st2[i])
			i++;
		if (!st2[i])
			return (0);
		st1++;
	}
	return (1);
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_putnbr(ft_op(av[1], av[2]));
	write(1, "\n", 1);
}
