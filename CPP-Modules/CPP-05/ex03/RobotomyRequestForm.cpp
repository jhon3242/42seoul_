/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:30:57 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/30 16:51:18 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: Form("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: Form("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) 
	: Form(obj), _target(obj._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this == &obj)
		return *this;
	_target = obj._target;
	Form::operator=(obj);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& excutor) const {
	if (!getSigned())
		throw Form::GradeTooLowException();
	else if (excutor.getGrade() > getGradeToExec())
		throw Form::GradeTooLowException();
	else {
		std::cout << "drrrrrrrrrrrrring noises" << std::endl;
		srand(time(NULL));
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomization of " << _target << " failed" << std::endl;
	}
}