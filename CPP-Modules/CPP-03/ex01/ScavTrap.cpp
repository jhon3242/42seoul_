/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:43:11 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 14:54:31 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_name = "ScavTrap";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) {
	*this = obj;
	std::cout << "ScavTrap " << _name << " has created." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has created." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " has destroyed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	_name = obj._name;
	_attackDamage = obj._attackDamage;
	_energyPoints = obj._energyPoints;
	_hitPoints = obj._hitPoints;
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is dead." << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " is out of energy." << std::endl;
	} else {
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attack " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now on Gate keeper mode." << std::endl;
}