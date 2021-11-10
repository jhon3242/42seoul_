/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 20:03:16 by wonjchoi          #+#    #+#             */
/*   Updated: 2021/09/18 20:15:59 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*p;

	p = argv[argc - 1];
	while (*p)
		write(1, p++, 1);
	write(1, "\n", 1);
	return (0);
}
