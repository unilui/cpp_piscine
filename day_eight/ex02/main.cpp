/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:43:32 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/25 16:49:39 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main()
{
	{
		MutantStack<int> mstack_x;
		std::cout << "Pushing 5 and 17 to the MutantStack" << std::endl;
		mstack_x.push(5);
		mstack_x.push(17);

		std::cout << "MutantStack top: ";
		std::cout << mstack_x.top() << std::endl;

		std::cout << "Popping item from MutantStack..." << std::endl;
		mstack_x.pop();

		std::cout << "MutantStack size: ";
		std::cout << mstack_x.size() << std::endl;

		std::cout << "Pushing 3, 5, 737 and 0 to the MutantStack" << std::endl;
		mstack_x.push(3);
		mstack_x.push(5);
		mstack_x.push(737);
		mstack_x.push(0);

		MutantStack<int>::iterator it = mstack_x.begin();
		MutantStack<int>::iterator ite = mstack_x.end();
		++it;
		--it;

		std::cout << "Showing MutantStack throught iterators:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack_x);
	}
	std::cout << "=========================================" << std::endl;
	{
		std::list<int> mstack_y;
		std::cout << "Pushing 5 and 17 to the list" << std::endl;
		mstack_y.push_back(5);
		mstack_y.push_back(17);

		std::cout << "List back: ";
		std::cout << mstack_y.back() << std::endl;

		std::cout << "Popping item from List..." << std::endl;
		mstack_y.pop_back();

		std::cout << "List size: ";
		std::cout << mstack_y.size() << std::endl;

		std::cout << "Pushing 3, 5, 737 and 0 to the list" << std::endl;
		mstack_y.push_back(3);
		mstack_y.push_back(5);
		mstack_y.push_back(737);
		mstack_y.push_back(0);

		std::list<int>::iterator it = mstack_y.begin();
		std::list<int>::iterator ite = mstack_y.end();
		++it;
		--it;

		std::cout << "Showing List throught iterators:" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack_y);
			return 0;
	}
}
