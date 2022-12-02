/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:55:36 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/02 14:58:21 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
	private :
		std::string _name;
	
	public :
		Data();
		Data(std::string name);
		Data(const Data& obj);
		~Data();
		Data& operator=(const Data& obj);
};

#endif