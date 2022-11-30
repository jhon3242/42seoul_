/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:28:45 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/30 17:16:17 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private :
		const std::string _name;
		bool _sigend;
		const int _gradeToSign;
		const int _gradeToExec;
	
	public :
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExec);
		Form(const Form& obj);
		virtual ~Form();
		Form& operator=(const Form& obj);

		const std::string getName(void) const;
		bool getSigned(void) const;
		int getGradeToSign(void) const;
		int getGradeToExec(void) const;

		void beSigned(const Bureaucrat& obj);
		virtual void execute(const Bureaucrat& execute) const = 0;

		std::runtime_error GradeTooHighException() const;
		std::runtime_error GradeTooLowException() const;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
