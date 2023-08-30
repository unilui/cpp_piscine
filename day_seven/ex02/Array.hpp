/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 19:36:42 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 19:36:46 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <sstream>

template <typename T>
class Array
{
private:
	T				*array;
	unsigned int	arraySize;

public:
	Array<T>(void) : array(NULL), arraySize(0)
	{
		std::cout << "Array default constructor called" << std::endl;
	};

	Array<T>(unsigned int n) : array(new T[n]), arraySize(n)
	{
		std::cout << "Array of size " << arraySize << " created." << std::endl;
	}

	Array<T>(const Array<T> &arrayToCopy)
		:	array(new T[arrayToCopy.size()]),
			arraySize(arrayToCopy.size())
	{
		for (unsigned int i = 0; i < arraySize; i++)
			array[i] = arrayToCopy.array[i];
	}

	~Array<T>( void )
	{
		delete[] array;
		std::cout << "Array default destructor called" << std::endl;
	}

	Array &operator=(const Array &arrayToCopy)
	{
		if (this == &arrayToCopy)
			return (*this);

		delete[] array;

		arraySize = arrayToCopy.size();
		array = new T[arraySize];

		for (unsigned int i = 0; i < arraySize; i++)
			array[i] = arrayToCopy.array[i];

		return (*this);
	}

	T &operator[](unsigned int i)
	{
		if (i >= arraySize)
			throw Array::OutOfLimitsException();
		return (array[i]);
	}

	unsigned int size(void) const
	{
		return (arraySize);
	}

	class OutOfLimitsException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Out of limits!");
			}
	};

};

#endif
