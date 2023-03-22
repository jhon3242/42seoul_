/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:59:51 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/03/22 14:33:03 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

double safePop(std::stack<double, std::list<double> >& stack) {
	double ret;
	if (!stack.empty()) {
		ret = stack.top();
		stack.pop();
		return ret;
	}
	throw "Error";
}

double calculate(std::string str) {
	std::stack<double, std::list<double> > stack;
	std::string tmp;
	double a;
	double b;
	double c;

	for (u_int i = 0; i < str.length(); i++) {
		if (str[i] == ' ')
			continue;
		if (str[i] == '(' || str[i] == ')')
			throw "Error";
		if (isdigit(str[i])) {
			tmp = str[i];
			while (isdigit(str[i + 1])) {
				tmp += str[i + 1];
				i++;
			}
			stack.push(std::stod(tmp));
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
			c = b / a;
			stack.push(c);
		}
	}
	return stack.top();
}

int RPN(std::string str) {
	double result;

	try {
		result = calculate(str);
		std::cout << result << std::endl;
        return 0;
	} catch(const char *e) {
        std::cerr << e << '\n';
        return 1;
    }
}