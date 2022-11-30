/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:15:58 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/30 16:56:07 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	
	std::cout << std::endl;
	std::cout << "TEST 1# : ShrubberyCreationForm() test" << std::endl;
	{
		try {
			Bureaucrat disable = Bureaucrat("disable", 150);
			Bureaucrat signable = Bureaucrat("signable", 145);
			Bureaucrat excutable = Bureaucrat("excutable", 137);
			ShrubberyCreationForm form;

			disable.signForm(form);
			disable.executeForm(form);
			std::cout << std::endl;

			signable.signForm(form);
			signable.executeForm(form);
			std::cout << std::endl;

			excutable.signForm(form);
			excutable.executeForm(form);
			std::cout << std::endl;
			
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "TEST 2# : RobotomyRequestForm() test" << std::endl;
	{
		try {
			Bureaucrat disable = Bureaucrat("disable", 150);
			Bureaucrat signable = Bureaucrat("signable", 72);
			Bureaucrat excutable = Bureaucrat("excutable", 45);
			RobotomyRequestForm form;

			disable.signForm(form);
			disable.executeForm(form);
			std::cout << std::endl;

			signable.signForm(form);
			signable.executeForm(form);
			std::cout << std::endl;

			excutable.signForm(form);
			excutable.executeForm(form);
			std::cout << std::endl;
			
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "TEST 2# : PresidentialPardonForm() test" << std::endl;
	{
		try {
			Bureaucrat disable = Bureaucrat("disable", 150);
			Bureaucrat signable = Bureaucrat("signable", 25);
			Bureaucrat excutable = Bureaucrat("excutable", 5);
			PresidentialPardonForm form;

			disable.signForm(form);
			disable.executeForm(form);
			std::cout << std::endl;

			signable.signForm(form);
			signable.executeForm(form);
			std::cout << std::endl;

			excutable.signForm(form);
			excutable.executeForm(form);
			std::cout << std::endl;
			
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	
}