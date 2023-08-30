/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:33 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 07:14:34 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat chatinho("Nildo", 1);

	std::cout << "Testing the bureaucrat ==========================" << std::endl;	
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

	std::cout << "Testing the form ==========================" << std::endl;
	try {
		Form burocratico("Adeus", 0, 1);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	try {
		Form burocratico("Adeus", 157, 1);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	Bureaucrat chatinho2("Nildo", 11);
	Form burocratico("Adeus", 10, 10);
	std::cout << burocratico;
	try {
		burocratico.beSigned(chatinho2);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	chatinho2.upGrade();
	burocratico.beSigned(chatinho2);
	return (0);
}
