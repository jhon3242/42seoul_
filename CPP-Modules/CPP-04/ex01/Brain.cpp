/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:44:21 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 14:45:41 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& obj) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}


Brain& Brain::operator=(const Brain& obj) {
	std::cout << "Brain overriding operator called" << std::endl;
	for (int i=0; i<100; i++)
		this->_ideas[i] = obj._ideas[i];
	return *this;
}