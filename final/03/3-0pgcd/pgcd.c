#include <stdio.h>
#include <stdlib.h>


int	ft_op(unsigned int n1, unsigned int n2)
{
	int	i;
	
	i = n1;
	while (i > 0)
	{
		if (n1 % i == 0 && n2 % i == 0)
			return (i);
		i--;
	}
	return (1);
}			

int main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", ft_op(atoi(av[1]), atoi(av[2])));
	printf("\n");
}
