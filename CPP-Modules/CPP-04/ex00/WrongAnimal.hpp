/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:05:32 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 14:38:16 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected :
		std::string _type;

	public : 
		WrongAnimal();
		WrongAnimal(const WrongAnimal& obj);
		virtual ~WrongAnimal();
		
		WrongAnimal& operator=(const WrongAnimal& obj);

		void makeSound() const;
		std::string getType() const;
};

#endif