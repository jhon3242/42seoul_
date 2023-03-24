/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:08:45 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/03/24 13:46:46 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int ft_stoi(const std::string &str)
{
	return atoi(str.c_str());
}

double ft_stod(std::string &str)
{
	return atof(str.c_str());
}

BitcoinExchange::BitcoinExchange(){};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) {
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj) {
	if (this != &obj) {
		_data = obj._data;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange(std::string fileName) {
	_db_file.open("db/data.csv");
	_input_file.open(fileName.c_str());
	if (!_db_file.is_open() || !_input_file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
	this->csvParser();
}

void BitcoinExchange::csvParser() {
	std::string line;
	std::getline(_db_file, line);
	while (std::getline(_db_file, line)) {
		std::string key = line.substr(0, line.find(','));
		std::string value = line.substr(line.find(',') + 1, line.length());
		_data[key] = ft_stod(value);
	}
}

BitcoinExchange::~BitcoinExchange() {
	_input_file.close();
	_db_file.close();
	_data.clear();
}

std::string ft_trim(std::string str) {
	std::string result = str;
	while (result[0] == ' ')
		result = result.substr(1, result.length());
	while (result[result.length() - 1] == ' ')
		result = result.substr(0, result.length() - 1);
	return result;
}

bool isDate(std::string date) {
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;
	
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}
	int year = ft_stoi(date.substr(0, 4));
	int month = ft_stoi(date.substr(5, 2));
	int day = ft_stoi(date.substr(8, 2));

	if (year < 2008 || year > 9999)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (month <= 7 && month % 2 == 0 && day > 30)
		return false;
	if (month > 7 && month % 2 == 1 && day > 30)
		return false;
	if (month == 2 && day > 29)
		return false;
	return true;
}

bool isPositive(std::string value) {
	while (value[0] == ' ')
		value = value.substr(1, value.length());
	if (value[0] == '-')
		return false;
	if (value.empty())
		return false;
	return true;
}

bool isInRange(std::string value) {
	try {
		if (ft_stod(value) >= 0.0 && ft_stod(value) <= 1000.0)
			return true;
		return false;
	} catch (const std::exception &e) {
		return false;
	}
}

bool isNumber(std::string value) {
	bool hasDecinam  = false;
	for (u_int i = 0; i < value.length(); i++) {
		if (i == 0 && value[i] == '-')
			continue;
		if (value[i] == '.' && !hasDecinam) {
			hasDecinam = true;
			continue;
		}
		if (!isdigit(value[i]))
			return false;
	}
	return true;
}

double BitcoinExchange::getExchangeRate(std::string date, std::string value) {
	if (!isDate(date))
		throw "Error: bad input";
	if (!isNumber(value))
		throw "Error: bad input";
	if (!isPositive(value))
		throw "Error: not a positive number.";
	if (value.empty())
		throw "Error: bad format empty value.";
	if (!isInRange(value))
		throw "Error: too large a number.";
	
	std::map<std::string, double>::const_iterator it = _data.upper_bound(date);
	if (it == _data.begin()) {
		throw "Error: no matched date.";
	} else {
		--it;
		return ft_stod(value) * it->second;
	}
}

void BitcoinExchange::printData(){
	std::string line;
	std::getline(_input_file, line);
	while (std::getline(_input_file, line)) {
		std::string date = ft_trim(line.substr(0, line.find('|')));
		std::string value = ft_trim(line.substr(line.find('|') + 1, line.length()));
		try {
			double exchangeRate = this->getExchangeRate(date, value);
			std::cout << date << " => " << value << " = " << exchangeRate << std::endl;
		} catch (const char *e) {
			if (std::string(e) == "Error: bad input")
				std::cout << e << " => " << line << std::endl;
			else
				std::cout << e <<std::endl;
		}
	}
}