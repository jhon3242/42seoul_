/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:45:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 13:49:52 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	protected :
		std::string _type;

	public : 
		Animal();
		Animal(const Animal& obj);
		virtual ~Animal();
		
		Animal& operator=(const Animal& obj);

		virtual void makeSound() const;
		std::string getType() const;
};

#endif