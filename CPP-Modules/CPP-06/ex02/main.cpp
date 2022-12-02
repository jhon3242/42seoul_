/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:19:45 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/02 15:32:42 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
	int type;
	Base* ret;

	std::srand(time(NULL));
	type = rand() % 3;
	if (type == 0)
		ret = new A();
	else if (type == 1)
		ret = new B();
	else
		ret = new C();
	return ret;
}

void identify(Base* ptr) {
	std::cout << "identify(Base* ptr)" << std::endl;
	if (dynamic_cast<A*>(ptr))
		std::cout << "I'm AAAAAAAA" << std::endl;
	if (dynamic_cast<B*>(ptr))
		std::cout << "I'm BBBBBBBB" << std::endl;
	if (dynamic_cast<C*>(ptr))
		std::cout << "I'm CCCCCCCC" << std::endl;
}

void identify(Base& ref) {
	std::cout << "identify(Base& ref)" << std::endl;
	try {
		A& a = dynamic_cast<A&>(ref);
		(void)a;
		std::cout << "I'm AAAAAAAA" << std::endl;
	} catch (std::exception& e) {};
	try {
		B& b = dynamic_cast<B&>(ref);
		(void)b;
		std::cout << "I'm BBBBBBBB" << std::endl;
	} catch (std::exception& e) {};
	try {
		C& c = dynamic_cast<C&>(ref);
		(void)c;
		std::cout << "I'm CCCCCCCC" << std::endl;
	} catch (std::exception& e) {};
}

int main() {
	Base* base = generate();
	identify(base);
	identify(*base);
	delete base;
}
