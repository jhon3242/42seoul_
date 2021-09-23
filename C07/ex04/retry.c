#include <stdlib.h>
#include <stdio.h>

int	is_space(char c)
{
	if ('\t' <= c && c <= '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	base_ck(char *base, int *len)
{
	int		aski[256];
	int		i;
	char	c;

	i = 0;
	while (i < 256)
		aski[i++] = 0;
	*len = 0;
	while (base[*len])
	{
		c = base[*len];
		if (aski[(int)c] || c == '+' || c == '-' || is_space(c))
			return (0);
		aski[(int)c] = 1;
		*len += 1;
	}
	if (*len < 1)
		return (0);
	return (1);
}

int	ft_atoi(char *src, char *base, int len)
{
	int	ret;
	int	sign;
	int	idx;

	ret = 0;
	sign = 1;
	while (is_space(*src))
		src++;
	while (*src == '-' || *src == '+')
	{
		if (*src == '-')
			sign -= -1;
		src++;
	}
	while (*src)
	{
		idx = 0;
		while (idx < len && base[idx] != *src)
			idx++;
		if (idx == len)
			break ;
		ret = ret * len + idx;
		src++;
	}
	return (ret * sign);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	f_len;
	int	t_len;

	if (!base_ck(base_from, &f_len) || !base_ck(base_to, &t_len))
		return (0);
	ft_atoi(nbr, base_from, f_len);
	return (0);
}

int main()
{
	printf("%d\n",ft_atoi("111", "01", 2));
}
