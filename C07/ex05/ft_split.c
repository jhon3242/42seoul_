/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:14:30 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/20 16:11:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (*charset == c)
			return (1);
		charset++;
	}
	return (0);
}

int	wc(char *str, char *charset)
{
	int	ret;

	ret = 0;
	while (*str)
	{
		if (is_charset(*str, charset))
			ret++;
		str++;
	}
	return (ret - 1);
}

char	*wd_split(char *str, char *charset)
{
	char	*ret;
	char	*tmp;
	int		len;

	len = 0;
	while (!is_charset(str[len], charset))
		len++;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	tmp = ret;
	while (len-- > 0 && *str)
	{
		*tmp = *str;
		tmp++;
		str++;
	}
	*tmp = 0;
	return (ret);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	char	**tmp;
	int		word_c;

	word_c = wc(str, charset);
	ret = (char **)malloc(sizeof(char *) * (word_c + 1));
	tmp = ret;
	while (*str)
	{
		if (is_charset(*str, charset) && *(str + 1))
		{
			*tmp = wd_split(str + 1, charset);
			tmp++;
		}
		str++;
	}
	*tmp = 0;
	return (ret);
}
