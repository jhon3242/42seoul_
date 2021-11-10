void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_atoi(unsigned int n)
{
	if (n > 9)
		ft_atoi(n / 10);
	ft_putnbr((n % 10) + '0');
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	n = nb;
	if (nb < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	ft_atoi(n);
}
