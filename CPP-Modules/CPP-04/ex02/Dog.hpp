/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:01:12 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 15:45:49 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "NewAnimal.hpp"
#include "Brain.hpp"

class Dog : public NewAnimal {
	private :
		Brain* _brain;

	public :
		Dog();
		Dog(const Dog& obj);
		~Dog();

		Dog& operator=(const Dog& obj);

		void makeSound() const;
};

#endif