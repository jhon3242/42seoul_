#include <stdlib.h>
#include <stdio.h>

int	ft_get_nb(char c, int len)
{
	char max_c;
	if (len <= 10)
		max_c = len + '0';
	else
		max_c = len + 'a' - 10;
	if ('0' <= c && c <= '9' && c <= max_c)
		return (c - '0');
	else if ('a' <= c && c <= 'f' && c <= max_c)
		return (c - 'a' + 10);
	else
		return (-1);
}



int	ft_atoi_base(const char *str, int str_base)
{
	int	sign;
	int ret;
	int tmp;

	sign = 1;
	if (*str == '-')
		sign *= -1;
	ret = 0;
	while (*str)
	{
		tmp = ft_get_nb(*str, str_base);
		//printf("%d\n",tmp);
		if (tmp >= 0)
			ret = ret * str_base + tmp;
		str++;
	}
	return (ret * sign);
}
	
int main(int ac, char **av)
{
	if (ac != 1)
		printf("%d\n",ft_atoi_base(av[1], atoi(av[2])));
}
