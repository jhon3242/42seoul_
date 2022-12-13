/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:39:33 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/13 14:50:38 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter (T* arr, int len, void (*f)(T&)) {
	for (int i=0; i<len; i++)
		f(arr[i]);
}

template <typename T>
void iter (const T* arr, int len, void (*f)(const T&)) {
	for (int i=0; i<len; i++)
		f(arr[i]);
}

template <typename T>
void print(T& x) {
	std::cout << x << " ";
}

template <typename T>
void addOne(T& x) {
	x += 1;
}

#endif