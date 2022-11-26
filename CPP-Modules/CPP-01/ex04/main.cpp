/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:59:09 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/26 13:50:08 by wonjchoi         ###   ########.fr       */
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

	size_t pos1 = 0;
	size_t pos2 = 0;
	while (true) {
		pos1 = buffer.find(string1, pos2);
		if (pos1 == std::string::npos)
			break;
		buffer.erase(pos1, string1.length());
		buffer.insert(pos1, string2);
		pos2 = pos1 + string2.length();
	}
	std::ofstream replaceFile(fileName + ".replace");
	replaceFile << buffer;
	replaceFile.close();
}