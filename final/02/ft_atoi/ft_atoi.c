int	is_space(char c)
{
	if ('\t' <= c && c <= '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	pm;
	int	ret;

	pm = 1;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			pm *= -1;
		str++;
	}
	ret = 0;
	while ('0' <= *str && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret * pm);
}
