int ft_count_if(char **tab, int length, int(*f)(char *))
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			ret++;
		i++;
	}
}
