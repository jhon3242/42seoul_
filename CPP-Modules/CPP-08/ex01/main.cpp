/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:05:04 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/05 14:16:03 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() {
	std::cout << "Test #1 default test" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test #2 custom test" << std::endl;
	{
		std::cout << std::endl;
		std::vector<int> arr(10000);
		std::srand(time(NULL));
		for (int i=0; i<10000; i++)
			arr[i] = std::rand() % 10000;
		
		Span sp2 = Span(10000);
		sp2.addNumber(arr.begin(), arr.end());
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	std::cout << std::endl;
}