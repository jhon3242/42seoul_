/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:54:46 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/04 14:14:48 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	private :
		T* _arr;
		unsigned int _size;
	
	public :
		Array() : _arr(new T[0]), _size(0){}

		Array(unsigned int n) : _arr(new T[n]) ,_size(n) {}

		Array(const Array& obj) {
			_arr = new T[obj._size];
			_size = obj._size;
			for (unsigned int i=0; i<_size; i++)
				_arr[i] = obj._arr[i];
		}

		~Array() {
			delete[] _arr;
		}

		Array& operator=(const Array& obj) {
			if (this == &obj)
				return *this;
			delete[] _arr;
			_arr = new T[obj._size];
			_size = obj._size;
			for (unsigned int i=0; i<_size; i++)
				_arr[i] = obj._arr[i];
			return *this;
		}

		T& operator[](unsigned int i) {
			if (i < 0 || i >= _size)
				throw std::out_of_range("Out of range");
			return _arr[i];
		}

		unsigned int size() const {return _size;}
};

#endif