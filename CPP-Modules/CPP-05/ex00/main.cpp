/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:15:58 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/30 14:21:50 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	std::cout << std::endl;
	std::cout << "TEST 1# : increment Grade" << std::endl;
	{
		try {
			Bureaucrat mike("mike", 2);
			std::cout << mike << std::endl;
			mike.incrementGrade();
			std::cout << mike << std::endl;
			mike.incrementGrade();
			std::cout << mike << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	std::cout << "TEST 2# : decrement Grade" << std::endl;
	{
		try {
			Bureaucrat mike("mike", 149);
			std::cout << mike << std::endl;
			mike.decrementGrade();
			std::cout << mike << std::endl;
			mike.decrementGrade();
			std::cout << mike << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
}