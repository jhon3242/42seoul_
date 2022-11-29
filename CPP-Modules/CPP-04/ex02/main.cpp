/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:07:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 15:50:37 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"


int main() {
	// const NewAnimal* animal = new NewAnimal();

	std::cout << "-----Test#1 new Dog()-----" << std::endl;
	{
		const NewAnimal* animal = new Dog();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;

	std::cout << "-----Test#2 new Cat()-----" << std::endl;
	{
		const NewAnimal* animal = new Cat();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;
	
	return 0;
}