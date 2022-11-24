/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:10:02 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/24 17:15:42 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	_firstName = "";
	_lastName = "";
	_nickName = "";
	_phoneNumber = "";
	_darkestSecret = "";
}

Contact::~Contact() {}

void Contact::setFirstName(std::string firstName) {
	_firstName = firstName;
}
void Contact::setLastName(std::string lastName) {
	_lastName = lastName;
}
void Contact::setNickName(std::string nickName) {
	_nickName = nickName;
}
void Contact::setPhoneNumber(std::string phoneNumber) {
	_phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(std::string darkestSecret) {
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void) const {
	return _firstName;
}
std::string Contact::getLastName(void) const {
	return _lastName;
}
std::string Contact::getNickName(void) const {
	return _nickName;
}
std::string Contact::getPhoneNumber(void) const {
	return _phoneNumber;
}
std::string Contact::getDarkestSecret(void) const {
	return _darkestSecret;
}
