#include <stdio.h>
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	size;
	int *ret;
	int	i;

	if (start < end)
		size = end - start + 1;
	else
		size = start - end + 1;
	ret = (int *)malloc(sizeof(size));
	i = 0;
	if (start < end)
	{
		while (end >= start)
		{
			ret[i++] = end;
			end--;
		}
	}
	else
	{
		while (end <= start)
		{
			ret[i++] = end;
			end++;
		}
	}
	return (ret);
}

int main()
{
	int	*p;

	p = ft_rrange(-1, 2);
	for (int i = 0; i < 4; i++)
		printf("%d\n",p[i]);
}
		

