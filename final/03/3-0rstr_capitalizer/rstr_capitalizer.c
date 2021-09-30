#include <unistd.h>

int	is_low(char c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int is_up(char c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	is_char(char c)
{
	if (is_up(c) || is_low(c))
		return (1);
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_op(char *str)
{
	int	flag;
	int	len;

	flag = 0;
	len = 0;
	while (str[len])
		len++;
	while (0 <= --len)
	{
		if (is_char(str[len]))
		{
			if (flag == 0)
			{
				if (is_low(str[len]))
				{
					str[len] = str[len] - 32;
					//write(1, &str[len], 1);
				}
			}
			else
			{
				if (is_up(str[len]))
					str[len] += 32;
			}
			flag = 1;
		}
		else
			flag = 0;
	}
	
	ft_putstr(str);
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		ft_op(av[i]);
		write(1, "\n", 1);
	}
}
