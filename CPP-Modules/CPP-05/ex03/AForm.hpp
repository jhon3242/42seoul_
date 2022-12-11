/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:20:59 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:43:27 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	private :
		const std::string _name;
		bool _sigend;
		const int _gradeToSign;
		const int _gradeToExec;
	
	public :
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExec);
		AForm(const AForm& obj);
		virtual ~AForm();
		AForm& operator=(const AForm& obj);

		const std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		void beSigned(const Bureaucrat& obj);
		virtual void execute(Bureaucrat const& excutor) const = 0;

		std::runtime_error GradeTooHighException() const;
		std::runtime_error GradeTooLowException() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
