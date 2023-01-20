/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:17:56 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/18 13:34:54 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_open.h"

int wrap_open(const char *path, int flags)
{
	int	fd;

	fd = open(path, flags);
	if (fd == -1)
		exit_with_error("File open fail\n");
	return (fd);
}