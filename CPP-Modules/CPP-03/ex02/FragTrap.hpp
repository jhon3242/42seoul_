/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:30:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/28 15:02:40 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private : 
	
	public : 
		FragTrap();
		FragTrap(const FragTrap& obj);
		FragTrap(std::string name);
		~FragTrap();

		FragTrap& operator=(const FragTrap& obj);
		
		void highFivesGuys(void);
};

#endif