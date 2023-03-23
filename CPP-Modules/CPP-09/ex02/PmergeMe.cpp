/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:40:32 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/03/23 12:41:40 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void process(int ac, char *av[]) {
	std::vector<int> arrV;
	std::deque<int> arrDq;
	container_fill(arrV, ac, av);
	container_fill(arrDq, ac, av);
	print_container(arrV , "vector" , true);
	print_container(arrDq , "deque" , false);
}