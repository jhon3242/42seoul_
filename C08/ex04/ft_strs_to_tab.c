#include <stdlib.h>
#include "ft_strock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ret;
	char	*tmp;

	ret = (char *)malloc(sizeof(ft_strlen(str) + 1));
	tmp = ret;
	while (*str)
		*(tmp++) = *(str++);
	*tmp = 0;
	return (ret);
}

struct	s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*p;
	int			i;

	i = 0;
	p = (t_strock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!p)
		return (0);
	while (i < ac)
	{
		p[i].size = ft_strlen(av[i]);
		p[i].str = ft_strdup(av[i]);
		p[i].copy = ft_strdup(av[i]);
		i++;
	}
	p[i].str = 0;
	return (p);
}