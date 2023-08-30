/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:44:50 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/28 19:01:20 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <list>
#include <iostream>
#include <sstream>
#include <climits>
#include <limits>
#include <string>
#include <ctime>

bool	hasOnlyNumbers(std::string const data)
{
	for (size_t i = 0; i < data.length(); i++)
	{
		if (data[i] < 48 || data[i] > 57)
			return (false);
	}
	return (true);
}

int    strToInt(std::string const data)
{
	int number;

	std::stringstream iss(data);
	iss >> number;

	return (number);
}

double  strToDouble(std::string const data)
{
	double number;

	std::stringstream iss(data);
	iss >> number;

	return (number);
}

bool	good_to_go(int argc)
{
	if (argc < 2)
	{
		std::cout
			<< "Usage: ./PmergeMe 9 8 7 6 5 4 3 2 1"
			<< std::endl;
		return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{
	if (!good_to_go(argc))
		return (1);

	std::deque<int> sourceDeque;
	std::list<int> sourceList;

	double elapsed_time_to_create_deque;
	double elapsed_time_to_create_list;
	double elapsed_time_to_verify;
	std::clock_t start_time;
	std::clock_t end_time;

	start_time = std::clock();

	std::deque<int> tmp_deque;
	std::deque<int>::iterator it;
	for (int i = 1; argv[i]; i++)
	{
		std::string tmp = std::string(argv[i]);
		if (!hasOnlyNumbers(tmp) || strToDouble(tmp) > INT_MAX)
		{
			std::cout << "Invalid arguments!" << std::endl;
			return (1);
		}
		it = std::find(tmp_deque.begin(), tmp_deque.end(), strToInt(tmp));
		if (it != tmp_deque.end())
		{
			std::cout << "Duplicates not allowed!" << std::endl;
			return (2);
		}
		tmp_deque.push_back(strToInt(tmp));
	}

	end_time = std::clock();

	elapsed_time_to_verify = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = std::clock();

	for (int i = 1; argv[i]; i++)
		sourceDeque.push_back(strToInt(std::string(argv[i])));

	end_time = std::clock();

	elapsed_time_to_create_deque = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

	start_time = std::clock();

	for (int i = 1; argv[i]; i++)
		sourceList.push_back(strToInt(std::string(argv[i])));

	end_time = std::clock();

	elapsed_time_to_create_list = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

	{
		std::deque<int> sortedDeque;
		std::deque<int>::iterator it;
		double elapsed_time_to_sort;

		std::cout << "Sorting with std::deque" << std::endl;

		std::cout << "Before: ";

		for (it = sourceDeque.begin(); it != sourceDeque.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::clock_t start_time = std::clock();

		sortedDeque = PmergeMe< std::deque<int> >::sort(sourceDeque);

		std::clock_t end_time = std::clock();

		elapsed_time_to_sort = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

		std::cout << "After: ";
		for (it = sortedDeque.begin(); it != sortedDeque.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout
			<< "Time to process a range of " << sourceDeque.size()
			<< " elements: " << (elapsed_time_to_verify + elapsed_time_to_create_deque + elapsed_time_to_sort)
			<< " seconds" << std::endl;
	}

	std::cout << std::endl << "===============================" << std::endl << std::endl;

	{
		std::list<int> sortedList;
		std::list<int>::iterator it;
		double elapsed_time_to_sort;

		std::cout << "Sorting with std::list" << std::endl;

		std::cout << "Before: ";

		for (it = sourceList.begin(); it != sourceList.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::clock_t start_time = std::clock();

		sortedList = PmergeMe< std::list<int> >::sort(sourceList);

		std::clock_t end_time = std::clock();

		elapsed_time_to_sort = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

		std::cout << "After: ";
		for (it = sortedList.begin(); it != sortedList.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout
			<< "Time to process a range of " << sourceList.size()
			<< " elements: " << (elapsed_time_to_verify + elapsed_time_to_create_list + elapsed_time_to_sort)
			<< " seconds" << std::endl;
	}

	return (0);
}
