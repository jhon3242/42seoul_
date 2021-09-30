int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign *= -1;

