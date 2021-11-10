int	is_up(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	dif;

	dif = 'A' - 'a';
	while (*str)
	{
		if (is_up(*str))
			*str += dif;
		str++;
	}
	return (str);
}
