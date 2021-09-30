#include <stdio.h>
#include <stdlib.h>


void	ft_op(char *s1, char *s2)
{
	unsigned int n1;
	unsigned int n2;
	int	c;
	int	i;
	int *ar;

	n1 = atoi(s1);
	n2 = atoi(s2);
	c = 0;
	i = 0;
	while (++i <= n1)
	{
		if (n1 % i == 0)
			c++;
	}
	ar = (int *)malloc(sizeof(int) * c);
	i = 0;
	while (++i <= n1)
	{
		if (n1 % i == 0)
			ar[--c] = i;
	}
	printf("%d",ar[0]);



int main(int ac, char **av)
{
	if (ac == 3)
		ft_op(av[1], av[2]);
	write(1, "\n", 1);
}
