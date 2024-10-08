/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:05:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/13 14:46:35 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) {
  *this = obj;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj) {
  (void)obj;
  return (*this);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i = 0;
	for (; i < 3; i++){
		if (formNames[i] == formName)
			break;
	}
	
	switch (i)
	{
		case 0:
			std::cout << "Intern creates PresidentialPardonForm " << std::endl;
			return new PresidentialPardonForm(target);
		case 1:
			std::cout << "Intern creates RobotomyRequestForm " << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates ShrubberyCreationForm " << std::endl;
			return new ShrubberyCreationForm(target);
	}
	throw Intern::unknownFormException();
}

std::runtime_error Intern::unknownFormException() const {
	return std::runtime_error("Intern : Unknown form");
}