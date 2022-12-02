/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:59:38 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/02 15:04:53 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main() {
	Data data;
	
	uintptr_t raw = serialize(&data);
	std::cout << (uintptr_t)&data << std::endl;
	std::cout << raw << std::endl;
	Data* ptr = deserialize(raw);
	std::cout << ((ptr == &data) ? "true" : "false") << std::endl;
}