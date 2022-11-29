/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:58:27 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 14:48:45 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& obj) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain();
	*this = obj;
}

Cat& Cat::operator=(const Cat& obj) {
	std::cout << "Cat overriding operator called" << std::endl;
	_type = obj._type;
	*_brain = *obj._brain;
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow~~~ Meow~~~" << std::endl;
}