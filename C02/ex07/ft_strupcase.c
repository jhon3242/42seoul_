int	is_low(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	dif;

	dif = 'A' - 'a';
	while (*str)
	{
		if (is_low(*str))
			*str += dif;
		str++;
	}
	return (str);
}
