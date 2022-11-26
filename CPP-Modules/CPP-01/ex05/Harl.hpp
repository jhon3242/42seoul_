/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:53:13 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/26 13:58:28 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <iostream>

class Harl {
	private :
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public :
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif