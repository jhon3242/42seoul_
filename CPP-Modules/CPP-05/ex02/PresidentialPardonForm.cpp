/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:53:16 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/30 16:54:46 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
	: Form("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
	: Form("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) 
	: Form(obj), _target(obj._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj) {
	if (this == &obj)
		return *this;
	_target = obj._target;
	Form::operator=(obj);
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& excutor) const {
	if (!getSigned())
		throw Form::GradeTooLowException();
	else if (excutor.getGrade() > getGradeToExec())
		throw Form::GradeTooLowException();
	else {
		std::cout << excutor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}