/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:33:07 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/02 14:37:07 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int ac, char *av[]) {
	if (ac != 2)
		std::cout << "Invalid input" << std::endl
			<< "Usage: ./convert [Argument to convert]" << std::endl;
	else {
		Conversion conv(av[1]);
		conv.putChar();
		conv.putInt();
		conv.putFloat();
		conv.putDouble();
	}
}