/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:54:33 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 08:10:44 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern escravo;
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
	Bureaucrat chatinho2("Nildo", 4);
	
	Form *burocratico = escravo.makeForm("Presidential", "Vitor");
	try {
		burocratico->execute(chatinho2);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	burocratico->beSigned(chatinho2);
	burocratico->execute(chatinho2);

	delete burocratico;
	std::cout << "Testing the Shrubbery Creation ==========================" << std::endl;
	Bureaucrat chatinho3("Nildo", 138);
	
	Form *burocratico1 = escravo.makeForm("ShrubberyCreation", "Vitor");
	try {
		burocratico1->execute(chatinho3);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	burocratico1->beSigned(chatinho3);
	chatinho3.upGrade();
	burocratico1->execute(chatinho3);

	delete burocratico1;
	std::cout << "Testing the Robotomy Request ==========================" << std::endl;
	Bureaucrat chatinho4("Nildo", 46);
	
	Form *burocratico2 = escravo.makeForm("Robotomy Request", "Vitor");
	try {
		burocratico2->execute(chatinho4);
	}	
	catch (const std::exception& e)	{
		std::cerr << e.what() << std::endl;
	}
	burocratico2->beSigned(chatinho4);
	chatinho4.upGrade();
	burocratico2->execute(chatinho4);
	
	delete burocratico2;

	std::cout << "Testing invalid form ==========================" << std::endl;
	Form *burocratico3 = escravo.makeForm("disgusting", "Vitor");
	(void)burocratico3;
	return (0);
}
