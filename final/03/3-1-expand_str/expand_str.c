#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_op(char *str)
{
	while (is_space(*str))
		str++;
	while (*str)
	{
		while (*str && !is_space(*str))
		{
			write(1, str, 1);
			str++;
		}
		if (!*str)
			return ;
		while (*str && is_space(*str))
			str++;
		if (!*str)
			return ;
		write(1, "   ", 3);
		}
}


int main(int ac, char **av)
{
	if (ac == 2)
		ft_op(av[1]);
	write(1, "\n", 1);
}
