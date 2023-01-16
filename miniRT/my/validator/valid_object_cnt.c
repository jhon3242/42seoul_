/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_object_cnt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaeyhan <chaeyhan@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:19:20 by chaeyhan          #+#    #+#             */
/*   Updated: 2023/01/16 15:37:05 by chaeyhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int count_ambient(void)
{
	static int cnt;

	return (cnt++);
}

int count_light(void)
{
	static int cnt;

	return (cnt++);
}

int count_camera(void)
{
	static int cnt;

	return (cnt++);
}