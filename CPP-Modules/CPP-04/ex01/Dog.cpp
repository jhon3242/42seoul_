/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:00:48 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 14:48:20 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& obj) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain();
	*this = obj;
}

Dog& Dog::operator=(const Dog& obj) {
	std::cout << "Dog overriding operator called" << std::endl;
	_type = obj._type;
	*_brain = *obj._brain;
	return *this;
}

Dog::~Dog() {
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Bow-wow! Bow-wow!" << std::endl;
}