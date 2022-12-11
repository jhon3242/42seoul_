/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:46:01 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:22:37 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: AForm(obj), _target(obj._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj) {
	if (this == &obj)
		return *this;
	_target = obj._target;
	AForm::operator=(obj);
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& excutor) const {
	if (!getSigned())
		throw AForm::GradeTooLowException();
	else if (excutor.getGrade() > getGradeToExec())
		throw AForm::GradeTooLowException();
	else {
		std::ofstream file(_target + "_shrubbery");
		file << "       _-_" << std::endl;
		file << "    /~~   ~~\\" << std::endl;
		file << " /~~         ~~\\" << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  /" << std::endl;
		file << "   ~  \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;
		file.close();
	}
}