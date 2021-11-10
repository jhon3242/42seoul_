int	ft_recursive_factorial(int nb)
{
	int	ret;

	if (nb == 0)
		return (1);
	if (nb < 0 )
		return (0);
	ret = nb * ft_recursive(nb - 1);
	return (ret);
}
