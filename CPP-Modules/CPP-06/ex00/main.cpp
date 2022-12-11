/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:33:07 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 16:38:14 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int ac, char *av[]) {
	if (ac != 2)
		std::cout << "Invalid input" << std::endl
			<< "Usage: ./convert [Argument to convert]" << std::endl;
	else {
		std::cout.precision(1);
		std::cout << std::fixed;
		
		Conversion conv(av[1]);
		conv.putChar();
		conv.putInt();
		conv.putFloat();
		conv.putDouble();
	}
}