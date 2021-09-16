int	g_pm;

int	is_pm(char c)
{
	if (c == '-' || c == '+')
	{
		if (c == '-')
			g_pm *= -1;
		return (1);
	}
	else
		return (0);
}

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;

	i = 0;
	g_pm = 1;
	while (is_space(*str))
		str++;
	while (is_pm(*str))
		str++;
	while ('0' <= *str && *str <= '9')
	{
		i = i * 10 + (*str - '0');
		str++;
	}
	return (i * g_pm);
}
