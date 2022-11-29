/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newAnimal.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:49:01 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 15:50:09 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWANIMAL_HPP
#define NEWANIMAL_HPP

#include <iostream>

class NewAnimal {
	protected :
		std::string _type;

	public : 
		NewAnimal();
		NewAnimal(const NewAnimal& obj);
		virtual ~NewAnimal();
		
		NewAnimal& operator=(const NewAnimal& obj);

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif