/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:07:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 14:52:38 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	std::cout << "-----Test#1 Animal Array-----" << std::endl;
	{
		Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};

		std::cout << std::endl;

		for (int i=0; i<4; i++)
			std::cout << "type : " << animals[i]->getType() << std::endl;

		std::cout << std::endl;
		
		for (int i=0; i<4; i++)
			delete animals[i];
	}
	
	
	return 0;
}