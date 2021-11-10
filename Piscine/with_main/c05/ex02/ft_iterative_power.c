int	ft_iterative_power(int nb, int power)
{
	int ret;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	ret = 1;
	while (i < power)
	{
		ret *= nb;
		i++;
	}
	return (ret);
}
