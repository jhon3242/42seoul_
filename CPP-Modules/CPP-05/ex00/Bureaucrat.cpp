/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:44:57 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/30 14:07:47 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {};

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name) {
	_grade = obj._grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this == &obj)
		return *this;
	_grade = obj._grade;
	return *this;
}


const std::string& Bureaucrat::getName(void) const {
	return _name;
}
int Bureaucrat::getGrade(void) const {
	return _grade;
}
void Bureaucrat::incrementGrade(void) {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}
void Bureaucrat::decrementGrade(void) {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::runtime_error Bureaucrat::GradeTooHighException() {
	return std::runtime_error("Grade Too High");
}
std::runtime_error Bureaucrat::GradeTooLowException() {
	return std::runtime_error("Grade Too Low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
  return (os);
}
