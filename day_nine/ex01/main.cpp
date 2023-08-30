/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:35:39 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 17:43:08 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

bool	good_to_go(int argc)
{
	if (argc != 2)
	{
		std::cout
			<< "Usage: ./RPN \"1 2 * 2 / 2 * 2 4 - +\""
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
		int result = RPN::evaluate(std::string(argv[1]));
		std::cout << "Result: " << result << std::endl;
	}
	catch (std::exception &error)
	{
		std::cout << error.what() << std::endl;
		return (2);
	}
	return (0);
}
