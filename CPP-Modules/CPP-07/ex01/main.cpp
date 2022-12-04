/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:47:31 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/04 13:53:16 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
	char charArr[] = "abcdef";
	int intArr[] = {1, 2, 3, 4, 5};
	float floatArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};

	iter(charArr, 6, print);
	std::cout << std::endl;
	iter(intArr, 5, print);
	std::cout << std::endl;
	iter(floatArr, 5, print);
	std::cout << std::endl;

	iter(charArr, 6, addOne);
	iter(intArr, 5, addOne);;
	iter(floatArr, 5, addOne);
	std::cout << std::endl;
	
	iter(charArr, 6, print);
	std::cout << std::endl;
	iter(intArr, 5, print);
	std::cout << std::endl;
	iter(floatArr, 5, print);
	std::cout << std::endl;
}