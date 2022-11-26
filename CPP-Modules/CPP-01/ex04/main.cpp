/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:59:09 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/25 23:08:31 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cout << "Only <fileName> <string1> <string2> is allowed" << std::endl;
		return (1);
	}
	std::string fileName = av[1];
	std::string string1 = av[2];
	std::string string2 = av[3];
	std::string buffer = "";

	std::ifstream file(fileName);
	while (file.good()) {
		char c = file.get();
		if (c >= 0) 
			buffer += c;
		else
			break;
	}
	file.close();
}