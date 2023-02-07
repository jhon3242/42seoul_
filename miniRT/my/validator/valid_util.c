/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:58:48 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/02/07 13:51:44 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	set_filter(int *filter, const char *valid_str)
{
	int	len;
	int	i;

	len = ft_strlen(valid_str);
	i = -1;
	while (++i < 128)
		filter[i] = 0;
	i = -1;
	while (++i < len)
		filter[(int)valid_str[i]] += 1;
}
