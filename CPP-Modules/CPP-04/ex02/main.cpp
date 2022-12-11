/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:07:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 13:02:49 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	// const AAnimal* animal = new AAnimal();

	std::cout << "-----Test#1 new Dog()-----" << std::endl;
	{
		const AAnimal* animal = new Dog();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;

	std::cout << "-----Test#2 new Cat()-----" << std::endl;
	{
		const AAnimal* animal = new Cat();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;
	
	return 0;
}