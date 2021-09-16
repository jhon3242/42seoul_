#include <unistd.h>

int	g_len;

int	base_ck(char *base)
{
	char	aski[256] = {0};
 	int		i;

	i = 0;
	while (base[i])
	i++;
	g_len = i;
	if (g_len <= 1)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		if (aski[*base] == 1)
			return (0);
		else
			aski[*base] = 1;
		base++;
	}
	return (1);
}

void	i_to_base(int nbr, char *base)
{
	if (nbr >= g_len)
	{
		i_to_base(nbr / g_len , base);
		i_to_base(nbr % g_len , base);
	}
	else
	{
		write(1, &base[nbr], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			pm;
	long long	tmp;

	tmp = nbr;
	if (!base_ck(base))
		return ;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp *= -1;
	}
	i_to_base(nbr, base);
}
