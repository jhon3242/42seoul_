/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choewonjun <wonjchoi@42seoul.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:45:22 by choewonju         #+#    #+#             */
/*   Updated: 2021/11/14 19:02:33 by choewonju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*re;

	if (*s1 || *s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if(!(re = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(re, s1, s1_len + 1);
	ft_strlcat(re + s1_len, s2, s2_len + 1);
	return (re);
}
