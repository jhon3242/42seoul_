/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:53:16 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:21:40 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) 
	: AForm(obj), _target(obj._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this == &obj)
		return *this;
	_target = obj._target;
	AForm::operator=(obj);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& excutor) const {
	if (!getSigned())
		throw AForm::GradeTooLowException();
	else if (excutor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	else {
		std::cout << excutor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}