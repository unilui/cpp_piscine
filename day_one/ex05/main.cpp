/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:02:34 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/25 04:40:58 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Harl	harl;

	std::cout << "\033[36m\nDEBUG:\033[0m" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\033[32m\nINFO:\033[0m" << std::endl;
	harl.complain("INFO");
	std::cout << "\033[33m\nWARNING:\033[0m" << std::endl;
	harl.complain("WARNING");
	std::cout << "\033[31m\nERROR:\033[0m" << std::endl;
	harl.complain("ERROR");
	std::cout << "\033[34m\nFOR SPORT:\033[0m" << std::endl;
	harl.complain("INVALID_LEVEL");
	return (0);
}
