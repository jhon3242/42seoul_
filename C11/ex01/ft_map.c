#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*ret;
	int	i;

	ret = (int *)malloc(sizeof(int) * length);
	if (!ret)
		return (0);
	i = -1;
	while (++i < length)
		ret[i] = f(tab[i]);
	return (ret);
}
