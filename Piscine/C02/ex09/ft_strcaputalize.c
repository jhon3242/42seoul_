int	is_up(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	is_low(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	is_char(char c)
{
	if (is_low(c) || is_up(c))
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_char(str[i]))
		{
			if (i == 0 && is_low(str[i]))
				str[i] += ('A' - 'a');
			else if (!is_char(str[i-1]) && is_low(str[i]))
				str[i] += ('A' - 'a');
			else if (is_char(str[i-1]) && is_up(str[i]))
				str[i] += ('a' - 'A');
		}
		i++;
	}
	return (str);
}
