/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:57:11 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/02 14:59:24 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _name("default") {}

Data::Data(std::string name) : _name(name) {}

Data::Data(const Data& obj){
	*this = obj;
}

Data::~Data() {}

Data& Data::operator=(const Data& obj) {
	if (this == &obj)
		return *this;
	_name = obj._name;
	return *this;
}