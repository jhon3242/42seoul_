/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:15:27 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/01/09 14:33:16 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPEN_H
# define FT_OPEN_H

# include <stdlib.h>
# include <sys/syslimits.h>
# include "minirt.h"

int	ft_open(const char *path, int flags);

#endif