/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:20:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:35:23 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() 
	: _name("default"), _sigend(false), _gradeToSign(150), _gradeToExec(150) {};

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExec) 
	:	_name(name),
		_sigend(false),
		_gradeToSign(gradeToSign), 
		_gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj) 
	:	_name(obj._name), 
		_sigend(obj._sigend), 
		_gradeToSign(obj._gradeToSign), 
		_gradeToExec(obj._gradeToExec) {}

AForm::~AForm() {};

AForm& AForm::operator=(const AForm& obj) {
	if (this == &obj)
		return *this;
	_sigend = obj._sigend;
	return *this;
}

const std::string AForm::getName(void) const {
	return _name;
}
bool AForm::getSigned(void) const {
	return _sigend;
}
int AForm::getGradeToSign(void) const {
	return _gradeToSign;
}
int AForm::getGradeToExec(void) const {
	return _gradeToExec;
}

void AForm:: beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() <= _gradeToSign)
		_sigend = true;
	else
		throw AForm::GradeTooLowException();
}

std::runtime_error AForm::GradeTooHighException() const {
	return std::runtime_error("Grade too high");
}
std::runtime_error AForm::GradeTooLowException() const {
	return std::runtime_error("Grade too low");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "Form name		: " << obj.getName() << std::endl;
	os << "Form sigend		: " << obj.getSigned() << std::endl;
	os << "Form grade to sign	: " << obj.getGradeToSign() << std::endl;
	os << "Form grade to exec	: " << obj.getGradeToExec() << std::endl;
	return os;
}