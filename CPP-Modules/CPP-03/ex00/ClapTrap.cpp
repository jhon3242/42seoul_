/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:12:00 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 14:54:44 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " has created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	*this = obj;
	std::cout << "ClapTrap " << _name << " has created." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " has created." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has destroyed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	_name = obj._name;
	_attackDamage = obj._attackDamage;
	_energyPoints = obj._energyPoints;
	_hitPoints = obj._hitPoints;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is dead." << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy." << std::endl;
	} else {
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attack " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
	} else if (_hitPoints < amount) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " die." << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount
		<< " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
	} else if (_energyPoints == 0) {
		std::cout << "ClapTrap " << _name << " is out of energy." << std::endl;
	} else {
		_hitPoints += amount;
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " be repaired " << amount
		<< " points!" << std::endl;
	}
}