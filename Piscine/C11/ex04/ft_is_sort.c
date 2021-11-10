int ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	ck;

	i = 0;
	while (i < legnth - 1)
	{
		if (i == 0)
			ck = f(tab[i], tab[i + 1]);
		if (f(tab[i], tab[i + 1] != ck && f(tab[i], tab[i + 1]) != 0))
			return (0);
		i++;
	}
	return (1);
}
