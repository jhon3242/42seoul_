/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:07:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 14:33:23 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main() {
	std::cout << "-----Test#1 new Animal()-----" << std::endl;
	{
		const Animal* animal = new Animal();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;

	std::cout << "-----Test#2 new Dog()-----" << std::endl;
	{
		const Animal* animal = new Dog();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;

	std::cout << "-----Test#3 new Cat()-----" << std::endl;
	{
		const Animal* animal = new Cat();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;

	std::cout << "-----Test#4 new WrongAnimal()-----" << std::endl;
	{
		const WrongAnimal* animal = new WrongAnimal();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;
	
	std::cout << "-----Test#5 new WrongCat()-----" << std::endl;
	{
		const WrongAnimal* animal = new WrongCat();
		std::cout << "type : " << animal->getType() << std::endl;
		std::cout << "makeSound() : ";
		animal->makeSound();
		delete animal;
	}
	std::cout << std::endl;
	return 0;
}