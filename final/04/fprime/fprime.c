#include <stdio.h>
#include <stdlib.h>

void	ft_op(int nb)
{
	int	i;

	i = 2;
	if (nb == 1)
	{
		printf("1");
		return ;
	}
	while (nb != i)
	{
		if (nb % i == 0)
		{
			printf("%d*",i);
			nb /= i;
			i--;
		}
		i++;
	}
	printf("%d",i);
}

int main(int ac, char **av)
{
	if (ac == 2)
		ft_op(atoi(av[1]));
	printf("\n");
}
