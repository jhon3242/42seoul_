int	is_low(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	while (*str)
	{
		if (!is_low(*str))
			return (0);
		str++;	
	}
	return (1);
}

