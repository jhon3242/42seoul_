/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:46:35 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/05 15:05:35 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	std::cout << std::endl;
	std::cout << "-----Test #1 : default test-----" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "mstack.top(): " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "mstack.size(): " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;

	std::cout << "-----Test #2 : default list test-----" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;

	std::cout << "-----Test #3 : Assignment test-----" << std::endl;
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);

		MutantStack<int> mstack2;
		mstack2 = mstack;
		mstack2.pop();

		std::cout << "mstack top() : " << mstack.top() << std::endl;
		std::cout << "mstack2 top() : " << mstack2.top() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "-----Test #4 : iterator test-----" << std::endl;
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "mstack default iterator : ";
		MutantStack<int>::iterator begin = mstack.begin();
		MutantStack<int>::iterator end = mstack.end();
		while (begin != end) {
			std::cout << *begin << " ";
			begin++;
		}
		std::cout << std::endl;
		
		std::cout << "mstack reverse iterator : ";
		MutantStack<int>::reverse_iterator rbegin = mstack.rbegin();
		MutantStack<int>::reverse_iterator rend = mstack.rend();
		while (rbegin != rend) {
			std::cout << *rbegin << " ";
			rbegin++;
		}
		std::cout << std::endl;

		std::cout << "mstack const iterator : ";
		MutantStack<int>::const_iterator cbegin = mstack.begin();
		MutantStack<int>::const_iterator cend = mstack.end();
		while (cbegin != cend) {
			std::cout << *cbegin << " ";
			cbegin++;
		}
		std::cout << std::endl;
		
		std::cout << "mstack const reverse iterator : ";
		MutantStack<int>::const_reverse_iterator crbegin = mstack.rbegin();
		MutantStack<int>::const_reverse_iterator crend = mstack.rend();
		while (crbegin != crend) {
			std::cout << *crbegin << " ";
			crbegin++;
		}
		std::cout << std::endl;
	}
	return 0;
}
