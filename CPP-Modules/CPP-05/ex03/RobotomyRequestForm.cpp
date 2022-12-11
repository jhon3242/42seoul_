/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:30:57 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:22:11 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) 
	: AForm(obj), _target(obj._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj) {
	if (this == &obj)
		return *this;
	_target = obj._target;
	AForm::operator=(obj);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& excutor) const {
	if (!getSigned())
		throw AForm::GradeTooLowException();
	else if (excutor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	else {
		std::cout << "drrrrrrrrrrrrring noises" << std::endl;
		srand(time(NULL));
		if (rand() % 2)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomization of " << _target << " failed" << std::endl;
	}
}