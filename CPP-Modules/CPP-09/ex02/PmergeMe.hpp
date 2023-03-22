/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonjchoi <wonjchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:38:27 by wonjchoi          #+#    #+#             */
/*   Updated: 2023/03/22 16:21:02 by wonjchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <deque>

void process(int ac, char *av[]);

template <typename T>
void container_fill(T &arr, int size, char *av[]) {
	try {
		for (int i = 1; i < size; i++) {
			if (std::stoi(av[i]) < 0)
				throw std::invalid_argument("Error");
			else
				arr.push_back(std::stoi(av[i]));
		}
	} catch (...) {
		std::cout << "Error" << std::endl;
		exit(1);
	}
}

template <typename T>
void insertion_sort(T& arr, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
void merge(T &arr, int left, int mid, int right) {
	std::vector<int> tmp(right - left + 1);
	int l = left;
	int m = mid + 1;
	int i = 0;
	while (l <= mid && m <= right) {
		if (arr[l] < arr[m])
            tmp[i++] = arr[l++];
        else
            tmp[i++] = arr[m++];
	}
	while (l <= mid)
        tmp[i++] = arr[l++];
    while (m <= right)
        tmp[i++] = arr[m++];
	for (int x = 0; x < i; x++)
        arr[left + x] = tmp[x];
}

template <typename T>
void merge_insert_sort(T &arr, int left, int right, int k) {
	if (left < right)
	{
		if (right - left <= k)
			insertion_sort(arr, left, right);
		else {
			int mid = left + (right - left) / 2;
			merge_insert_sort(arr, left, mid, k);
			merge_insert_sort(arr, mid + 1, right, k);
			merge(arr, left, mid, right);
		}
	}
}

template <typename T>
void print_container(T &arr, std::string name, bool print) {
	u_int size = arr.size();
	if (print) {
		std::cout << "Before: ";
		for (u_int j = 0; j < size; j++) {
            if (size <= 5)
                std::cout << arr[j] << " ";
            else
            {
                if (j < 4)
                    std::cout << arr[j] << " ";
                else
                {
                    std::cout << "[...]";
                    break;
                }
            }
        }
        std::cout << std::endl;
	}

	std::clock_t start_time = std::clock();
    merge_insert_sort(arr, 0, size - 1, 10);
    std::clock_t end_time = std::clock();

	if (print) {
		std::cout << "After: ";
        for (u_int j = 0; j < size; j++) {
            if (size <= 5)
                std::cout << arr[j] << " ";
            else
            {
                if (j < 4)
                    std::cout << arr[j] << " ";
                else
                {
                    std::cout << "[...]";
                    break;
                }
            }
        }
		std::cout << std::endl;
	}
	double diff_time = static_cast<double>(end_time - start_time) / (CLOCKS_PER_SEC / 1000000.0);
    std::cout << "Time to process a range of " << size <<" elements with std::[" << name << "] : " << diff_time << " us" << std::endl;
}

#endif