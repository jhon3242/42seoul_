/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:42:43 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/25 14:46:26 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdio.h>

int main() {
	Zombie *horde = zombieHorde(10, "Horde");

	for (int i = 0; i< 10; i++) {
		horde[i].announce();
	}

	delete[] horde;
	return 0;
}