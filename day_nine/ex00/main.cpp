/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 04:17:44 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 09:36:01 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <algorithm>
#include <map>
#include <string>
#include <iostream>

bool    good_to_go(int argc)
{
    if (argc != 2)
    {
        std::cout 
            << "Usage: ./btc <input_file>"
            << std::endl;
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    if (!good_to_go(argc))
        return (1);

    try 
    {
        BitcoinExchange::loadDataBase("data.csv");
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
        return (2);
    }

    try 
    {
        BitcoinExchange::pricesConsult(std::string(argv[1]));
    }
    catch (std::exception &error)
    {
        std::cout << error.what() << std::endl;
        return (2);
    }
    return (0);
}