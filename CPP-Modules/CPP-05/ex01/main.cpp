/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:15:58 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/30 15:22:51 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	
	std::cout << std::endl;
	std::cout << "TEST 1# : Sign constructor excpetion grade too high" << std::endl;
	{
		try {
			Form form("Test Form", 0, 0);
			std::cout << form << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "TEST 2# : Sign constructor excpetion grade too low" << std::endl;
	{
		try {
			Form form("Test Form", 151, 151);
			std::cout << form << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "TEST 3# : signForm() normal test" << std::endl;
	{
		try {
			Bureaucrat mike("mike", 2);
			Form form("Test Form", 5, 100);
			std::cout << form << std::endl;
			mike.signForm(form);
			std::cout << form << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "TEST 4# : signForm() excpetion test" << std::endl;
	{
		try {
			Bureaucrat mike("mike", 2);
			Form form("Test Form", 1, 100);
			std::cout << form << std::endl;
			mike.signForm(form);
			std::cout << form << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}