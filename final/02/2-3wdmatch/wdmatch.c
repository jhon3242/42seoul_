#include <unistd.h>

void	ft_op(char *s1, char *s2)
{
	char *tmp;

	tmp = s1;
	while (*tmp)
	{
		while (*s2 && *tmp != *s2)
			s2++;
		if (!*s2)
			return ;
		tmp++;
	}
	while (*s1)
		write(1, s1++, 1);
}

int main(int ac, char **av)
{
	if (ac == 3)
		ft_op(av[1], av[2]);
	write(1, "\n", 1);
}
