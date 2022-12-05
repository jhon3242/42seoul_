/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:18:31 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/05 13:22:39 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <queue>

int main() {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> q;

	for (int i = 0; i < 10; i++){
		v.push_back(i);
		l.push_back(i);
		q.push_back(i);
	}

	std::cout << "vector	: " << *easyfind(v, 5) << std::endl;
	std::cout << "list	: " << *easyfind(v, 5) << std::endl;
	std::cout << "deque	: " << *easyfind(v, 5) << std::endl;
	return 0;
}