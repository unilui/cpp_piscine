/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:26:39 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/22 12:09:31 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

int main(void)
{   
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::cout <<  "Testing with Vector: " << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;

    try
    {
        std::cout << "Using easyfind to find element 3 on my vector: " << std::endl;
        std::cout << *easyfind(v, 3) << std::endl;

        std::cout << "Using easyfind to find element 42 on my vector: " << std::endl;
        std::cout << *easyfind(v, 42) << std::endl;
    } catch (std::string &e)
    {
        std::cout << e << std::endl;
    }


    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);

    std::cout << "Testing with List: " << std::endl;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl << std::endl;

    try
    {
        std::cout << "Using easyfind to find element 3 on my list: " << std::endl;
        std::cout << *easyfind(l, 3) << std::endl;

        std::cout << "Using easyfind to find element 42 on my list: " << std::endl;
        std::cout << *easyfind(l, 42) << std::endl;
    } catch (std::string &e)
    {
        std::cout << e << std::endl;
    }
    return 0;
}