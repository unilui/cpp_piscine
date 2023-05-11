/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/10 21:49:09 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) { return ; }
PhoneBook::~PhoneBook( void ) { return ; }

void	PhoneBook::show_contacts( void )
{
	std::cout << "\n---------------------------------------------\n";
	std::cout << "|" << std::setw(10) << std::right << "Index";
	std::cout << "|" << std::setw(10) << std::right << "First Name";
	std::cout << "|" << std::setw(10) << std::right << "Last Name";
	std::cout << "|" << std::setw(10) << std::right << "Nickname";
	std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------\n";

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << std::right << (i + 1);
		std::cout << this->contacts[i].summary();
	}
	std::cout << "---------------------------------------------\n\n";
}

void	PhoneBook::search( void )
{
	std::string	contact_index;
	int			index;
	int			tries;

	tries = 
	this->show_contacts();
	std::cout << "Enter the contact to display: ";
	std::cin >> contact_index;
	index = std::stoi(contact_index);
	if (index < 1 || index > 8)
		std::cout << "Contact not found... Damn it :(";
}
