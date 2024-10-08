/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:04:18 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/02/07 13:49:34 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		exit_with_error("Malloc failed\n");
	return (ret);
}
