/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:15:58 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:40:54 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	
	std::cout << std::endl;
	std::cout << "TEST 1# : Intern makeForm() success test" << std::endl;
	{
		try {
			Intern newbie;
			AForm* scf;
			AForm* rrf;
			AForm* ppf;

			scf = newbie.makeForm("shrubbery creation", "mike");
			rrf = newbie.makeForm("robotomy request", "jack");
			ppf = newbie.makeForm("presidential pardon", "jason");

			std::cout << *scf << std::endl;
			std::cout << *rrf << std::endl;
			std::cout << *ppf << std::endl;

			delete scf;
			delete rrf;
			delete ppf;
			
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "TEST 2# : Intern makeForm() fail test" << std::endl;
	{
		try {
			Intern newbie;
			AForm* notExist;
			
			notExist = newbie.makeForm("what the hell", "name");
			std::cout << *notExist << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}