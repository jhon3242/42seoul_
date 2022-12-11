/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:52:38 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/11 15:21:19 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESICENTIALPARDONFORM_HPP
#define PRESICENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private :
		std::string _target;

	public : 
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

		void execute(Bureaucrat const& excutor) const;
};

#endif