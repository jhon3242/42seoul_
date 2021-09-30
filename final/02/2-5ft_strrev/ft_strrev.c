#include <stdio.h>

char	*ft_strrev(char *str)
{
	int	i;
	int	len;
	char	tmp;

	i = 0;
	while (str[i])
		i++;
	len = i;
	i = -1;
	while (++i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 -i];
		str[len - 1 - i] = tmp;
	}
	return (str);
}

int main()
{
	char st[] = "abcdefghijk";
	printf("%s",ft_strrev(st));
	return (0);
}
