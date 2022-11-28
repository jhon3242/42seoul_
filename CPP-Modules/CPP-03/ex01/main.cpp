/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:33:18 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 14:56:49 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap jack("jack");
	ScavTrap mike("mike");

	std::cout << std::endl;
	std::cout << "-----Test #1 attack-----" << std::endl;
	for(int i=0; i<50; i++){
		jack.attack("mike");
	}
	jack.attack("mike");
	jack.beRepaired(10);
	std::cout << std::endl;

	std::cout << "-----Test #2 Gate keeper mode-----" << std::endl;
	mike.guardGate();
	std::cout << std::endl;
}