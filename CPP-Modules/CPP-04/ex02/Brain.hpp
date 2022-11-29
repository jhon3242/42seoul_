/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:42:38 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/29 14:44:18 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
	private :
		std::string _ideas[100];

	public :
		Brain();
		Brain(const Brain& obj);
		~Brain();

		Brain& operator=(const Brain& obj);
};

#endif