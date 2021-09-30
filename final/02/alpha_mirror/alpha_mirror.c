#include <unistd.h>

void	ft_op(char *str)
{
	int	tmp;
	char	c;

	while (*str)
	{
		if ('a' <= *str && *str <= 'z')
		{
			tmp = 'z' - *str;
			c = 'a' + tmp;
			write(1, &c, 1);
		}
		else if ('A' <= *str && *str <= 'Z')
		{
			tmp = 'Z' - *str;
			c = 'A' + tmp;
			write(1, &c, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_op(av[1]);
	write(1, "\n", 1);
}
