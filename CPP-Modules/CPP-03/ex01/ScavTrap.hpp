/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:30:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 15:02:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private : 
	
	public : 
		ScavTrap();
		ScavTrap(const ScavTrap& obj);
		ScavTrap(std::string name);
		~ScavTrap();

		ScavTrap& operator=(const ScavTrap& obj);
		
		void attack(const std::string& target);
		void guardGate();
};

#endif