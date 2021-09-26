#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *ch)
{
	int	i;

	i = 0;
	while (*ch++)
		i++;
	return (i);
}

char	*ft_strcat(char *a, char *b)
{
	while (*b)
		*a++ = *b++;
	return (a);
}

char	*sumup(int size, char *a, char **strs, char *sep)
{
	int		i;
	char	*f;

	i = 0;
	f = a;
	while (i < size)
	{
		a = ft_strcat(a, strs[i]);
		if (i != size - 1)
			a = ft_strcat(a, sep);
		i++;
	}
	return (f);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*a;
	int		i;
	int		total;

	i = 0;
	total = 0;
	while (i < size)
		total += ft_strlen(strs[i++]) + ft_strlen(sep);
	total -= ft_strlen(sep);
	a = (char *)malloc(sizeof(char) * total);
	if (!a)
		return (0);
	if (size == 0)
	{
		a = malloc(sizeof(char) * 1);
		a[0] = 0;
		return (a);
	}
	return (sumup(size, a, strs, sep));
}


int	main(void)
{
	char	a[] = "elephant";
	char	b[] = "cat";
	char	c[] = "egg";
	char	*p[3];
	p[0] = a;
	p[1] = b;
	p[2] = c;
	char *test[] = { };
	printf("%s",ft_strjoin(0, test, ", "));
}
