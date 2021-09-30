#include <stdio.h>
#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_op(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] && !is_space(str[i]))
			write(1, &str[i++], 1);
		if (!str[i])
			return ;
		if (is_space(str[i]))
		{
			
			while (str[i] && is_space(str[i]))
				i++;
			if (!str[i])
				return ;
			write(1, " ", 1);
			i--;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_op(av[1]);
	write(1, "\n", 1);
}
