/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:44:47 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/25 16:38:34 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>()
	{
		std::cout << "MutantStack default constructor called." << std::endl;
	}

	MutantStack(const MutantStack &other) : std::stack<T>(other)
	{
		std::cout << "MutantStack copy constructor called." << std::endl;
	}

	virtual ~MutantStack( void )
	{
		std::cout << "MutantStack destroyed." << std::endl;
	}

	MutantStack &operator=(const MutantStack &other)
	{
		if (this != &other) {
			std::stack<T>::operator=(other);
		}
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return std::stack<T>::c.begin();
	}

	iterator end()
	{
		return std::stack<T>::c.end();
	}

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	reverse_iterator rbegin()
	{
		return std::stack<T>::c.rbegin();
	}

	reverse_iterator rend()
	{
		return std::stack<T>::c.rend();
	}
};

#endif
