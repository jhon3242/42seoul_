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
	if (!p)
		return (0);
	tmp = p;
	while (min < max)
	{
		*p = min;
		p++;
		min++;
	}
	return (tmp);
}
