#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	ret;
	unsigned int i;

	i = 0;
	while (i < len)
	{
		if (i == 0)
			ret = tab[0];
		else if (ret < tab[i])
			ret = tab[i];
		i++;
	}
	return (ret);
}

int main()
{
	int ar[] = {1, 2, 10,8, 2, 4};
	printf("%d", max(ar, 6));
}
