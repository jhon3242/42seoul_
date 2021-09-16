int	g_len;

int	is_space(char ch)
{
	if (ch == ' ' || ('\t' <= ch && ch <= '\r'))
		return (1);
	else
		return (0);
}

int	base_ck(char *base)
{
	char	aski[256];
	int		i;

	i = 0;
	while (i < 256)
		aski[i++] = 0;
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
		if (is_space(*base))
			return (0);
		if (aski[(unsigned int)*base] == 1)
			return (0);
		else
			aski[(unsigned int)*base] = 1;
		base++;
	}
	return (1);
}

int	is_base_str(char ch, char *base)
{
	while (*base)
	{
		if (ch == *base)
			return (1);
		base++;
	}
	return (0);
}

int	str_to_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			break ;
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	pm;
	int	nb;

	pm = 1;
	nb = 0;
	if (!base_ck(base))
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pm *= -1;
		str++;
	}
	while (is_base_str(*str, base))
	{
		nb = nb * g_len + str_to_base(*str, base);
		str++;
	}
	return (nb * pm);
}
