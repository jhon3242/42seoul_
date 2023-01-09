/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vunit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:59:56 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 17:00:00 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vunit(t_vec3 vec)
{
	const double	len = vlength(vec);

	if (len == 0)
	{
		perror("Error\nDevider is 0\n");
		exit(EXIT_FAILURE);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}
