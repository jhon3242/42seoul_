#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int	i;

	i = 2;
	while (i <= n)
	{
		if (i == n)
			return (1);
		i = i * 2;
	}
	return (0);
}

int main()
{
	for (int i = 1; i<100; i++)
		printf("%d %d\n", i, is_power_of_2(i));
}
