/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:26:46 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/02 14:17:55 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <cmath>

class Conversion {
	private :
		std::string _input;
		double _double;
		bool isChar() const;
	
	public :
		Conversion();
		Conversion(std::string input);
		Conversion(const Conversion& obj);
		~Conversion();

		Conversion& operator=(const Conversion& obj);

		char toChar(void) const;
		int toInt(void) const;
		float toFloat(void) const;
		double toDouble(void) const;

		void putChar();
		void putInt();
		void putFloat();
		void putDouble();
};

#endif