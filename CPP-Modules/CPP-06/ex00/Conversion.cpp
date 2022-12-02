/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:29:50 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/02 14:40:55 by wonjchoi         ###   ########.fr       */
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

char Conversion::toChar(void) const {
	return (static_cast<char>(_double));
};
int Conversion::toInt(void) const {
	return (static_cast<int>(_double));
};
float Conversion::toFloat(void) const {
	return (static_cast<float>(_double));
};
double Conversion::toDouble(void) const {
	return (static_cast<double>(_double));
};

void Conversion::putChar() {
	std::cout << "char: ";
	if (std::isnan(_double) || std::isinf(_double))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(toChar()))
		std::cout << "'" << toChar() << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}
void Conversion::putInt() {
	std::cout << "int: ";
	if (std::isnan(_double) || std::isinf(_double))
		std::cout << "impossible" << std::endl;
	else
		std::cout << toInt() << std::endl;
}
void Conversion::putFloat() {
	std::cout << "float: ";
	if (std::isnan(_double) || std::isinf(_double))
		std::cout << std::showpos << toFloat() << "f" <<  std::endl;
	else if (toFloat() == static_cast<int>(toFloat()))
		std::cout << toFloat() << ".0f" << std::endl;
	else
		std::cout << toFloat() << "f" << std::endl;
}
void Conversion::putDouble() {
	std::cout << "double: ";
	if (std::isnan(_double) || std::isinf(_double))
		std::cout << std::showpos << toDouble() <<  std::endl;
	else if (toDouble() == static_cast<int>(toDouble()))
		std::cout << toDouble() << ".0" << std::endl;
	else
		std::cout << toDouble() << std::endl;
}