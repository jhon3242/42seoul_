/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:08:20 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/25 14:42:53 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	private : 
		std::string _name;
	
	public :
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void announce() const;
		void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif