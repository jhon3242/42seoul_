int	is_print(char c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (is_print(*str))
			return (0);
		str++;
	}
	return (1);
}
