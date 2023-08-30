/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:38:40 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/22 17:52:08 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>

int main( void )
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Vector: " << std::endl;
	for (std::vector<int>::const_iterator it = sp.getNumbers().begin(); it != sp.getNumbers().end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "Trying to add a number to a full vector: " << std::endl;
	try
	{
		sp.addNumber(42);
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Trying to find the shortest span on a vector with less than 2 elements: " << std::endl;
	try
	{
		Span sp2 = Span(1);
		sp2.addNumber(42);
		std::cout << sp2.shortestSpan() << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Trying to find the longest span on a vector with less than 2 elements: " << std::endl;
	try
	{
		Span sp2 = Span(1);
		sp2.addNumber(42);
		std::cout << sp2.longestSpan() << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Adding a lot of numbers to a vector at once: " << std::endl;

	Span sp2 = Span(10000);
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);

	sp2.addNumber(v.begin(), v.end());
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	return 0;
}
