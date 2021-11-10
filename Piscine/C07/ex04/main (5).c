/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:31:56 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/22 17:28:01 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long long	g_size;
int			g_index;
int	ft_atoi_base(char *str, char *base);

int	base_ck_c(char *base)
{
	char	aski[256];
	int		i;

	i = 0;
	while (i < 256)
		aski[i++] = 0;
	i = 0;
	while (base[i])
		i++;
	g_size = i;
	if (g_size <= 1)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		if (aski[(unsigned int)*base] == 1)
			return (0);
		else
			aski[(unsigned int)*base] = 1;
		base++;
	}
	return (1);
}

void	i_to_base(long long nbr, char *base, char *tmp_ptr)
{
	if (nbr >= g_size)
	{
		i_to_base(nbr / g_size, base, tmp_ptr);
		i_to_base(nbr % g_size, base, tmp_ptr);
	}
	else
	{
		tmp_ptr[g_index] = base[nbr];
		g_index++;
	}
}

char	*ft_putnbr_base(int nbr, char *base)
{
	long long	tmp;
	int			count;
	char		*ret;

	tmp = nbr;
	if (tmp < 0)
		tmp *= -1;
	count = 0;
	while (tmp > 0)
	{
		tmp /= g_size;
		count++;
	}
	ret = (char *)malloc(sizeof(char) * count + 1);
	if (!ret)
		return (0);
	g_index = 0;
	i_to_base(tmp, base, ret);
	ret[g_index] = 0;
	return (ret);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	tmp;
	if (!base_ck_c(base_from) || !base_ck_c(base_to))
		return (0);
	tmp = ft_atoi_base(nbr, base_from);
	printf("%d\n", tmp);
	printf("answer : %s\n",ft_putnbr_base(tmp, base_to));
	return (0);
}

int main()
{
	char	nbr[] = "a";
	char	base_from[] = "0123456789abcdef";
	char	base_to[] = "01";	
	ft_convert_base(nbr, base_from, base_to);
	return (0);
}
