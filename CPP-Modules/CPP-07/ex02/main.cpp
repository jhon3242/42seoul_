/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:03:43 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/04 14:17:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
	std::cout << std::endl;
	std::cout << "Test#1 Constructor  Array<int>" << std::endl;
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < 5; i++)
			arr[i] = i;
		for (unsigned int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test#2 Constructor  Array<char>" << std::endl;
	{
		Array<char> arr(5);
		for (unsigned int i = 0; i < 5; i++)
			arr[i] = 'a' + i;
		for (unsigned int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test#3 Copy contsrcutor " << std::endl;
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < 5; i++)
			arr[i] = i;
		Array<int> arr2(arr);
		for (unsigned int i = 0; i < 5; i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Test#4 Copy  assignment" << std::endl;
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < 5; i++)
			arr[i] = i;

		Array<int> arr2(arr);
		for (unsigned int i = 0; i < 5; i++)
			arr2[i] = 10 + i;
			
		arr = arr2;
		for (unsigned int i = 0; i < 5; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "Test#5 Out of range" << std::endl;
	{
		Array<int> arr(5);
		for (unsigned int i = 0; i < 5; i++)
			arr[i] = i;
		
		try {
			std::cout << arr[5] << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}

	std::cout << "Test#6 size" << std::endl;
	{
		Array<int> arr(5);
		std::cout << arr.size() << std::endl;
	}
	return 0;
}