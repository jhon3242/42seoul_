#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*p;
	int	i;
	int	ret;

	i = 0;
	p = malloc(sizeof(int) * (max - min));
	if (!p)
		return (-1);
	if (min >= max)
	{
		p = 0;
		return (0);
	}
	ret = max - min;
	while (min < max)
	{
		p[i++] = min++;
	}
	*range = p;
	return (ret);
}

int	main(void)
{
	int *p;
	int i;
	int size;

	i =0;
	size = ft_ultimate_range(&p, -10, 10);
	while (i < size)
	{
		printf("%d\n",p[i++]);
	}
}
