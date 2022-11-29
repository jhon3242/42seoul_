/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:56:35 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 15:45:33 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "NewAnimal.hpp"
#include "Brain.hpp"

class Cat : public NewAnimal {
	private :
		Brain* _brain;

	public :
		Cat();
		Cat(const Cat& obj);
		~Cat();

		Cat& operator=(const Cat& obj);

		void makeSound() const;
};

#endif