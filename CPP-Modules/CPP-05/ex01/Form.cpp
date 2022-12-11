/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:37:07 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:16:57 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() 
	: _name("default"), _sigend(false), _gradeToSign(150), _gradeToExec(150) {};

Form::Form(const std::string& name, int gradeToSign, int gradeToExec) 
	:	_name(name),
		_sigend(false),
		_gradeToSign(gradeToSign), 
		_gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& obj) 
	:	_name(obj._name), 
		_sigend(obj._sigend), 
		_gradeToSign(obj._gradeToSign), 
		_gradeToExec(obj._gradeToExec) {}

Form::~Form() {};

Form& Form::operator=(const Form& obj) {
	if (this == &obj)
		return *this;
	_sigend = obj._sigend;
	return *this;
}

const std::string Form::getName(void) const {
	return _name;
}
bool Form::getSigned(void) const {
	return _sigend;
}
int Form::getGradeToSign(void) const {
	return _gradeToSign;
}
int Form::getGradeToExec(void) const {
	return _gradeToExec;
}

void Form:: beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() <= _gradeToSign)
		_sigend = true;
	else
		throw Form::GradeTooLowException();
}

std::runtime_error Form::GradeTooHighException() const {
	return std::runtime_error("Grade too high");
}
std::runtime_error Form::GradeTooLowException() const {
	return std::runtime_error("Grade too low");
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form name		: " << obj.getName() << std::endl;
	os << "Form sigend		: " << obj.getSigned() << std::endl;
	os << "Form grade to sign	: " << obj.getGradeToSign() << std::endl;
	os << "Form grade to exec	: " << obj.getGradeToExec() << std::endl;
	return os;
}