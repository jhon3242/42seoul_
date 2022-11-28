/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:33:18 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 13:47:51 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap jack("jack");
	ClapTrap mike("mike");

	std::cout << std::endl;
	std::cout << "-----Test #1 attack-----" << std::endl;
	for(int i=0; i<10; i++){
		jack.attack("mike");
	}
	jack.attack("mike");
	jack.beRepaired(10);
	std::cout << std::endl;

	std::cout << "-----Test #2 takeDemage-----" << std::endl;
	for(int i=0; i<10; i++){
		jack.takeDamage(1);
	}
	jack.takeDamage(10);
	jack.beRepaired(10);
	std::cout << std::endl;

	std::cout << "-----Test #3 beRepaired-----" << std::endl;
	for(int i=0; i<9; i++){
		mike.takeDamage(1);
	}
	mike.beRepaired(10);
	mike.takeDamage(2);
	mike.beRepaired(1);
	std::cout << std::endl;
}