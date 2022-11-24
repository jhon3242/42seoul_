/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:12 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/11/24 17:48:05 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {
	private:
		std::string _resizeing(std::string str) const;
		std::string _readLine() const;
		void _addContact();
		void _searchContact() const;
		void _printShortInfo() const;
		void _printDetailInfo(Contact contact) const;
		int _contactIndex;
		Contact _contacts[8];
	
	public:
		void process();
};

#endif