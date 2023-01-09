/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vlength.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:59:38 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 16:59:39 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vlength(t_vec3 vec)
{
	return (sqrt(vlength2(vec)));
}
