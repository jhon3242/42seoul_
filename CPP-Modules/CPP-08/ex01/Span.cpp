/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:34:39 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/05 14:13:08 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _v() {}

Span::Span(unsigned int n) : _n(n), _v() {}

Span::Span(const Span& obj) {
	*this = obj;
}

Span::~Span() {}

Span& Span::operator=(const Span& obj) {
	if (this != &obj) {
		_n = obj._n;
		_v = obj._v;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (_v.size() >= _n)
		throw::std::runtime_error("Span is full");
	_v.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (_v.size() + (end - begin) > _n)
		throw std::runtime_error("Span dosen't have enough space");
	for (std::vector<int>::iterator it = begin; it != end; it++)
		_v.push_back(*it);
}

int Span::shortestSpan() {
	unsigned int result = UINT_MAX;
	std::vector<int> tmp(_v);
	if (_v.size() <= 1)
		throw std::runtime_error("Not enough numbers");
	for (unsigned int i=0; i<tmp.size() - 1; i++)
		result = std::min(result, (unsigned int)(tmp[i + 1] - tmp[i]));
	return result;
}
int Span::longestSpan() {
	if (_v.size() <= 1)
		throw std::runtime_error("Not enough numbers");
	return *std::max_element(_v.begin(), _v.end()) -  *std::min_element(_v.begin(), _v.end());
}