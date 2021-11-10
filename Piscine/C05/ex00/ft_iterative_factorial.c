int	ft_iterative_factorial(int nb)
{
	int	ret;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	ret = 1;
	while (nb > 0)
	{
		ret *= nb;
		nb--;
	}
	return (ret);
}
~
~
