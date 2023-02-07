/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_object_cnt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:20 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/02/07 13:53:26 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_ambient(void)
{
	static int	cnt;

	return (cnt++);
}

int	count_light(void)
{
	static int	cnt;

	return (cnt++);
}

int	count_camera(void)
{
	static int	cnt;

	return (cnt++);
}
