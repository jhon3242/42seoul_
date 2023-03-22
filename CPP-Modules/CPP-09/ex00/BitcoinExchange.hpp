/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:47:44 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/03/22 13:07:18 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <ctype.h>

class BitcoinExchange {
	private :
		std::ifstream _db_file;
		std::ifstream _input_file;
		std::map<std::string, double> _data;
	
	public :
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& obj);
		BitcoinExchange(std::string);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& obj);

		double getExchangeRate(std::string, std::string);
		void csvParser();
		void printData();
};


#endif