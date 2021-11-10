#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int is_low(char c)
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

int is_char (char c)
{
	if (is_low(c) || is_up(c))
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
	int flag;
	char *tmp;

	flag = 0;
	tmp = str;
	while (is_space(*str))
		str++;
	while (*str)
	{
		if (is_char(*str))
		{
			if (flag == 1)
			{
				if (is_up(*str))
					*str += 32;
			}
			else
			{
				if (is_low(*str))
					*str -= 32;
				flag = 1;
			}
		}
		else
			flag = 0;
		str++;
	}
	ft_putstr(tmp);
}

int main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 1)
	{
		i = 1;
		while (i < ac)
		{
			ft_op(av[i]);
			//if (i != ac - 1)
			//	write(1, "\n", 1);
			i++;
		}
	}
}
