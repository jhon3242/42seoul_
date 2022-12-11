/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:00:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:40:36 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public :
		Intern();
		Intern(const Intern& obj);
		~Intern();
		Intern& operator=(const Intern& obj);
		
		AForm* makeForm(const std::string& formName, const std::string& target);

		std::runtime_error unknownFormException() const;
};

#endif