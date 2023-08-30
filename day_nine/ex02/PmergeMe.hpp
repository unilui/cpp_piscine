/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:39:27 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/28 17:56:04 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

template <typename Container>
class PmergeMe
{
private:
	static Container	mainGroup;
	static Container	firstGroup;
	static Container	secondGroup;

	PmergeMe( void ) { return ; }
	~PmergeMe( void ) { return ; }

	PmergeMe(PmergeMe const &PmergeMeToCopy)
	{
		static_cast<void>(PmergeMeToCopy);
	}

	PmergeMe &operator=(PmergeMe const &PmergeMeToCopy)
	{
		static_cast<void>(PmergeMeToCopy);
		return *this;
	}

	static void	createGroups( void )
	{
		bool	switch_group = true;

		while (!mainGroup.empty())
		{
			if (switch_group)
				firstGroup.push_back(mainGroup.back());
			else
				secondGroup.push_back(mainGroup.back());
			mainGroup.pop_back();
			switch_group = !switch_group;
		}
	}

	static void distinguishGroups( void )
	{
		typename Container::iterator first;
		typename Container::iterator second;

		first = firstGroup.begin();
		second = secondGroup.begin();

		while (second != secondGroup.end())
		{
			if (*first > *second)
			{
				int temp = *first;
				*first = *second;
				*second = temp;
			}
			first++;
			second++;
		}
	}

	template <typename Iterator>
	static void merge(Iterator first, Iterator middle, Iterator last, bool reverse)
	{
		Container leftGroup(first, middle);
		Container rightGroup(middle, last);

		Iterator it = first;
		while (!leftGroup.empty() && !rightGroup.empty())
		{
			if (!reverse)
			{
				if (leftGroup.front() > rightGroup.front())
				{
					*it++ = leftGroup.front();
					leftGroup.pop_front();
				} else
				{
					*it++ = rightGroup.front();
					rightGroup.pop_front();
				}
			}
			else
			{
				if (leftGroup.front() <= rightGroup.front())
				{
					*it++ = leftGroup.front();
					leftGroup.pop_front();
				} else
				{
					*it++ = rightGroup.front();
					rightGroup.pop_front();
				}
			}
		}

		while (!leftGroup.empty())
		{
			*it++ = leftGroup.front();
			leftGroup.pop_front();
		}

		while (!rightGroup.empty())
		{
			*it++ = rightGroup.front();
			rightGroup.pop_front();
		}
	}

	template <typename Iterator>
	static void mergeSort(Iterator first, Iterator last, bool reverse)
	{
		if (std::distance(first, last) <= 1)
			return;

		Iterator middle = first;
		std::advance(middle, std::distance(first, last) / 2);

		mergeSort(first, middle, reverse);
		mergeSort(middle, last, reverse);

		merge(first, middle, last, reverse);
	}

	static void	insert(int value_to_insert)
	{
		typename Container::iterator it = secondGroup.begin();
		int	right = secondGroup.size();
		int	left = 0;

		while (true)
		{
			typename Container::iterator middle = it;
			std::advance(middle, (left + right) / 2);
			if (value_to_insert > *middle)
			{
				left += 1;
				if (left > right)
				{
					typename Container::iterator tmp = it;
					std::advance(tmp, (left - 1));
					secondGroup.insert(tmp, value_to_insert);
					return ;
				}
			}
			if (value_to_insert < *middle)
			{
				right -= 1;
				if (right < left)
				{
					typename Container::iterator tmp = it;
					std::advance(tmp, (right + 1));
					secondGroup.insert(tmp, value_to_insert);
					return ;
				}
			}
		}
	}

	static void	binaryInsert(void)
	{
		while (!firstGroup.empty())
		{
			insert(firstGroup.front());
			firstGroup.pop_front();
		}
	}

public:
	static Container	sort(Container &sourceGroup)
	{
		mainGroup = sourceGroup;

		createGroups();
		distinguishGroups();
		mergeSort(firstGroup.begin(), firstGroup.end(), false);
		mergeSort(secondGroup.begin(), secondGroup.end(), true);
		binaryInsert();

		return (Container(secondGroup.begin(), secondGroup.end()));
	}
};

template <typename Container>
Container	PmergeMe<Container>::mainGroup;

template <typename Container>
Container	PmergeMe<Container>::firstGroup;

template <typename Container>
Container	PmergeMe<Container>::secondGroup;

#endif
