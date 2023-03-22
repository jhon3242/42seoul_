/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:56:11 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/03/22 14:20:45 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char *av[])
{
	if (ac != 2) {
		std::cout << "Error : wrong argument." << std::endl;
        return 1;
	}
	return (RPN(av[1]));
}