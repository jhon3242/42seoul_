int	is_nbr(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	while (*str)
	{
		if (!is_nbr(*str))
			return (0);
		str++;	
	}
	return (1);
}
