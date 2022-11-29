/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewAnimal.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:48:56 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 15:48:58 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewAnimal.hpp"

NewAnimal::NewAnimal() : _type("NewAnimal") {
	std::cout << "NewAnimal constructor called" << std::endl;
}

NewAnimal::NewAnimal(const NewAnimal& obj) {
	std::cout << "NewAnimal copy constructor called" << std::endl;
	*this = obj;
}

NewAnimal& NewAnimal::operator=(const NewAnimal& obj) {
	std::cout << "NewAnimal overriding operator called" << std::endl;
	_type = obj._type;
	return *this;
}

NewAnimal::~NewAnimal() {
	std::cout << "NewAnimal destructor called" << std::endl;
}

void NewAnimal::makeSound() const {
	std::cout << "NewAnimal sound" << std::endl;
}

std::string NewAnimal::getType() const {
	return _type;
}