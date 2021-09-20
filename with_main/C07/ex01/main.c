#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*p;
	int			*tmp;
	long long	size;

	if (min >= max)
		return (0);
	size = max - min;
	p = (int *)malloc(sizeof(int) * (size));
	tmp = p;
	while (min < max)
	{
		*p = min;
		p++;
		min++;
	}
	return (tmp);
}

int main()
{
	int	*p;
	int i;

	p = ft_range(-10, 10);
	i = 0;
	while (i++ < 20)
		printf("%d\n", *(p++));
}
