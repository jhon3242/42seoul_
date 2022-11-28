/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:33:18 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 15:07:28 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap jack("jack");
	FragTrap mike("mike");

	std::cout << std::endl;
	std::cout << "-----Test #1 attack-----" << std::endl;
	jack.attack("mike");
	std::cout << std::endl;

	std::cout << "-----Test #2 highFivesGuys-----" << std::endl;
	mike.highFivesGuys();
	std::cout << std::endl;
}