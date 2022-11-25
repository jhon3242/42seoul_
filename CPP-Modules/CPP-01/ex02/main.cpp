/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:49:02 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/25 15:01:52 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string hi = "HI THIS IS BRAIN";
	std::string *stringPTR = &hi;
	std::string &stringREF = hi;

	std::cout << &hi << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << hi << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}