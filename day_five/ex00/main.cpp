/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:33 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 05:45:48 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat chatinho("Nildo", 1);
	try {
		Bureaucrat chatinho1("Nilda", 0);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat chatinho1("Nilda", 151);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		chatinho.upGrade();
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << chatinho;
	chatinho.downGrade();
	std::cout << chatinho;
	chatinho.upGrade();
	std::cout << chatinho;
}
