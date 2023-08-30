/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:43:04 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/22 17:47:16 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

class Span
{
private:
	unsigned int numberOfElements;
	std::vector<int> data;

	Span( void );

public:
	Span(unsigned int N);
	Span(const Span &other);
	virtual ~Span( void );
	Span &operator=(const Span &other);

	void	addNumber(int number);
	void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	int		shortestSpan( void );
	int		longestSpan( void );

	int		getNumberOfElements() const;
	const std::vector<int> &getNumbers() const;

	class IllegalOpException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif
