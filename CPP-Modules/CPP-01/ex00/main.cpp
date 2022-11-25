/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:20:25 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/25 14:31:30 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
	Zombie foo("Foo");
	foo.announce();

	randomChump("randomChump");

	Zombie *newZombie1 = newZombie("newZombie");
	newZombie1->announce();
	delete newZombie1;

	return (0);
}