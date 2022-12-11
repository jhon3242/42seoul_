/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:29:50 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 16:57:14 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

bool Conversion::isChar() const {
	return _input.length() == 1 && !std::isdigit(_input[0]);
}

Conversion::Conversion() : _input(""), _double(0) {}

Conversion::Conversion(std::string input) {
	_input = input;
	if (isChar())
		_double = static_cast<double>(_input[0]);
	else
		_double = std::strtod(_input.c_str(), NULL);
}
Conversion::Conversion(const Conversion& obj) {
	*this = obj;
}
Conversion::~Conversion() {}

Conversion& Conversion::operator=(const Conversion& obj) {
	if (this != &obj) {
		_input = obj._input;
		_double = obj._double;
	}
	return *this;
}

void Conversion::putChar() {
	char c = static_cast<char>(_double);
	double tmp = static_cast<double>(c);

	std::cout << "char: ";
	if (c > 0 ? floor(_double) == tmp : ceil(_double) == tmp) {
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	} else
		std::cout << "impossible" << std::endl;
}
void Conversion::putInt() {
	int d = static_cast<int>(_double);
	double tmp = static_cast<double>(d);

	std::cout << "int: ";
	if (d > 0 ? floor(_double) == tmp : ceil(_double) == tmp)
		std::cout << d << std::endl;
	else
		std::cout << "impossible" << std::endl;
}
void Conversion::putFloat() {
	float f = static_cast<float>(_double);

	std::cout << "float: ";
	if (isinf(f) && !isinf(_double))
		std::cout << "impossible" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}
void Conversion::putDouble() {
	std::cout << "double: " << _double << std::endl;
}