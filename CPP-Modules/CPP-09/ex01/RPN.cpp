/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:59:51 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/03/23 14:33:05 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

double ft_stod(std::string &str)
{
	return atof(str.c_str());
}

double safePop(std::stack<double, std::list<double> >& stack) {
	double ret;
	if (!stack.empty()) {
		ret = stack.top();
		stack.pop();
		return ret;
	}
	throw "Error: Invalid input format.";
}

double calculate(std::string str) {
	std::stack<double, std::list<double> > stack;
	std::string tmp;
	double a;
	double b;
	double c;
	double r;

	for (u_int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue;
		if (str[i] == '(' || str[i] == ')')
			throw "Error: Invalid input format.";
		if (isdigit(str[i]) || (str[i] == '-' && isdigit(str[i + 1]))) {
			tmp = str[i];
			while (isdigit(str[i + 1])) {
				tmp += str[i + 1];
				i++;
			}
			if (str[i + 1] != 0 && str[i + 1] != ' ')
				throw "Error: Invalid input format.";
			if (ft_stod(tmp) >= 10)
				throw "Error: Number must be less than 10.";
			stack.push(ft_stod(tmp));
			tmp.clear();
		}
		
		if (str[i] == '+') {
			a = safePop(stack);
			b = safePop(stack);
			c = a + b;
			stack.push(c);
		} else if (str[i] == '-') {
			a = safePop(stack);
			b = safePop(stack);
			c = b - a;
			stack.push(c);
		} else if (str[i] == '*') {
			a = safePop(stack);
			b = safePop(stack);
			c = a * b;
			stack.push(c);
		} else if (str[i] == '/') {
			a = safePop(stack);
			b = safePop(stack);
			if (a == 0)
				throw "Error: Cannot divied by zero.";
			c = b / a;
			stack.push(c);
		}
	}
	r = safePop(stack);
	if (stack.empty())
		return r;
	throw "Error: Invalid input format.";
}

int RPN(std::string str) {
	double result;

	try {
		result = calculate(str);
		std::cout << result << std::endl;
		return 0;
	} catch(const char *e) {
		std::cout << e << '\n';
		return 1;
	}
}