#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int *ret;
	int	i;

	if (min >= max)
		return (0);
	size = max - min;
	ret = malloc(sizeof(int) * size);
	if (!ret)
		return (-1);
	i = 0;
	while (i < size)
	{
		ret[i++] = min;
		min++;
	}
	*range = ret;
	return (size);
}

int main()
{
	int *p[2];

	ft_ultimate_range(p, -10, 10);
	for (int i=0; i<20; i++)
		printf("%d\n",p[0][i]);
}