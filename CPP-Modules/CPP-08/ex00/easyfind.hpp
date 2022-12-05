/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:05:51 by wonjchoi          #+#    #+#             */
/*   Updated: 2022/12/05 13:22:09 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int n) {
	typename T::iterator result = std::find(container.begin(), container.end(), n); // iterator 는 일종의 포인터임
	if (result == container.end())
		throw std::exception();
	return result;
}

#endif