/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 05:32:56 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/28 18:11:42 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <exception>
#include <string>
#include <iostream>

bool    good_to_go(int argc)
{
    if (argc != 2)
    {
        std::cout
            << "Usage: ./scalar_converter <scalar_to_convert>"
            << std::endl;
        return (false);
    }
    return (true);
}

int main(int argc, char **argv)
{
    if (!good_to_go(argc))
        return (1);

    ScalarConverter theory;

    try
    {
        theory.convert(std::string(argv[1]));
	}
	catch (const std::exception& e)
    {
		std::cerr << e.what() << std::endl;
        return (2);
	}

    return (0);
}
