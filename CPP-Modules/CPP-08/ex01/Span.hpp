/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:23:54 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/05 14:12:34 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <exception>

class Span {
	private :
		unsigned int _n;
		std::vector<int> _v;
	
	public :
		Span();
		Span(unsigned int n);
		Span(const Span& obj);
		~Span();
		Span& operator=(const Span& obj);

		void addNumber(int num);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
  		int longestSpan();
};

#endif