/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:35:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:31:16 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
	private :
		const std::string _name;
		int _grade;

	public :
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string& getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(AForm& obj);
		void executeForm(AForm const& form);
		
		std::runtime_error GradeTooHighException();
		std::runtime_error GradeTooLowException();
		
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif