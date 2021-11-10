/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:15:03 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/20 16:41:45 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ret_strlen(int size, char **strs)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < size)
	{
		ret += ft_strlen(strs[i]);
		i++;
	}
	ret += size;
	return (ret - 1);
}

void	ft_strcpy(char *dec, char *src)
{
	while (*src)
	{
		*dec = *src;
		dec++;
		src++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*ret;
	char	*tmp;
	int		strlen;
	int		i;

	strlen = ret_strlen(size, strs);
	ret = (char *)malloc(sizeof(char) * (strlen + 1));
	tmp = ret;
	i = 0;
	while (i < size)
	{
		while (*strs[i])
		{
			*tmp = *strs[i];
			tmp++;
			strs[i]++;
		}
		*tmp = *sep;
		tmp++;
		i++;
	}
	*(--tmp) = 0;
	return (ret);
}
