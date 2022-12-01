/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:52:18 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/01 21:16:28 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _rawBits(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& obj) {
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw) {
	_rawBits = raw;
}

int Fixed::toInt(void) const {
	return _rawBits >> _fractionalBits;
}

float Fixed::toFloat(void) const {
	return (float)_rawBits / (1 << _fractionalBits);
}

bool Fixed::operator>(const Fixed& obj) const {
	return _rawBits > obj.getRawBits();
}
bool Fixed::operator<(const Fixed& obj) const {
	return _rawBits < obj.getRawBits();
}
bool Fixed::operator>=(const Fixed& obj) const {
	return _rawBits >= obj.getRawBits();
}
bool Fixed::operator<=(const Fixed& obj) const {
	return _rawBits <= obj.getRawBits();
}
bool Fixed::operator==(const Fixed& obj) const {
	return _rawBits == obj.getRawBits();
}
bool Fixed::operator!=(const Fixed& obj) const {
	return _rawBits != obj.getRawBits();
}

Fixed operator+(const Fixed& obj) const;
Fixed operator-(const Fixed& obj) const;
Fixed operator*(const Fixed& obj) const;
Fixed operator/(const Fixed& obj) const;

Fixed& operator++();
Fixed operator++(int);
Fixed& operator--();
Fixed operator--(int);

static Fixed& min(Fixed& a, Fixed& b);
static const Fixed& min(const Fixed& a, const Fixed& b);
static Fixed& max(Fixed& a, Fixed& b);
static const Fixed& max(const Fixed& a, const Fixed& b);

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

