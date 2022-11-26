/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:33:43 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/26 14:34:44 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	harl.complain("debug");
	std::cout << std::endl;
	harl.complain("info");
	std::cout << std::endl;
	harl.complain("warning");
	std::cout << std::endl;
	harl.complain("error");
	std::cout << std::endl;
}