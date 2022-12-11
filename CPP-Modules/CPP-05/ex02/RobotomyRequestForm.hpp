/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:16:41 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:22:18 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private :
		std::string _target;

	public : 
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

		void execute(Bureaucrat const& excutor) const;
};

#endif