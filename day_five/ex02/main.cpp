/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:33 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 07:47:22 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

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

	std::cout << "Testing the Presidential Pardon ==========================" << std::endl;
	Bureaucrat chatinho2("Nildo", 26);
	PresidentialPardonForm burocratico("Adeus");
	try {
		burocratico.beSigned(chatinho2);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	chatinho2.upGrade();
	burocratico.beSigned(chatinho2);
	
	std::cout << "Testing the Shrubbery Request ==========================" << std::endl;
	Bureaucrat chatinho3("Nildo", 138);
	
	ShrubberyCreationForm burocratico1("Adeus");
	try {
		burocratico1.execute(chatinho3);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	burocratico1.beSigned(chatinho3);
	chatinho3.upGrade();
	burocratico1.execute(chatinho3);

	std::cout << "Testing the Robotomy Request ==========================" << std::endl;
	Bureaucrat chatinho4("Nildo", 46);
	
	RobotomyRequestForm burocratico2("Adeus");
	try {
		burocratico2.execute(chatinho4);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	burocratico2.beSigned(chatinho4);
	chatinho4.upGrade();
	burocratico2.execute(chatinho4);
	return (0);
}
