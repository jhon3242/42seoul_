/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:02:17 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 13:02:23 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
	protected :
		std::string _type;

	public : 
		AAnimal();
		AAnimal(const AAnimal& obj);
		virtual ~AAnimal();
		
		AAnimal& operator=(const AAnimal& obj);

		virtual void makeSound() const = 0;
		std::string getType() const;
};

#endif