#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*p;

	len = ft_strlen(src);
	p = malloc(sizeof(char) * (len + 1));
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = 0;
	return (p);
}
