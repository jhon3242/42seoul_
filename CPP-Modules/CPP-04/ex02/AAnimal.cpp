/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:01:59 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 13:02:01 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = obj;
}

AAnimal& AAnimal::operator=(const AAnimal& obj) {
	std::cout << "AAnimal overriding operator called" << std::endl;
	_type = obj._type;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal sound" << std::endl;
}

std::string AAnimal::getType() const {
	return _type;
}