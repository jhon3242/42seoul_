#include <unistd.h>

int is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_op(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i && is_space(str[i]))
		i--;
	if (i == 0)
		return ;
	while (!is_space(str[i]))
		i--;
	i++;
	while (str[i] && !is_space(str[i]))
	{
		write(1, &str[i++], 1);
	}
}


int main(int argc, char **argv)
{
	if (argc == 2)
		ft_op(argv[1]);
	write(1, "\n", 1);
}
