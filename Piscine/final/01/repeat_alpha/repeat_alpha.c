#include <unistd.h>

int	ft_ct_idx(char c)
{
	if ('a' <= c && c <= 'z')
		return (c - 'a' + 1);
	if ('A' <= c && c <= 'Z')
		return (c - 'A' + 1);
	return (1);
}

void	ft_fun(char *str)
{
	int	size;

	while (*str)
	{
		size = ft_ct_idx(*str);
		while (size-- > 0)
			write(1, str, 1);
		str++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		ft_fun(argv[1]);
	write(1, "\n", 1);
}
