/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:43:11 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 15:03:52 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_name = "FragTrap";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has created." << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) {
	*this = obj;
	std::cout << "FragTrap " << _name << " has created." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has created." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " has destroyed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	_name = obj._name;
	_attackDamage = obj._attackDamage;
	_energyPoints = obj._energyPoints;
	_hitPoints = obj._hitPoints;
	return *this;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " gives high five!" << std::endl;
}