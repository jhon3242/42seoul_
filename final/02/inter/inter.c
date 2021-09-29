#include <unistd.h>

void	ft_op(char *s1, char *s2)
{
	char	aski[256];
	int		i;

	i = 0;
	while (i < 256)
		aski[i++] = 0;
	while (*s2)
	{
		if (aski[(int)*s2] == 0)
		{
			aski[(int)*s2] = 1;
		}
		s2++;
	}
	while (*s1)
	{
		if (aski[(int)*s1] == 1)
		{
			aski[(int)*s1] = 2;
			write(1, s1, 1);
		}
		s1++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_op(argv[1], argv[2]);
	write(1, "\n", 1);
}
