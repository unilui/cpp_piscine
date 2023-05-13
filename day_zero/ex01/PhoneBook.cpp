/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/13 18:40:21 by lufelip2         ###   ########.fr       */
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

int		PhoneBook::get_contact_index( void )
{
	std::string	contact_index;
	int			index;

	for (int tries = 0; tries < 3; tries++)
	{
		std::cout << "Enter the contact to display: ";
		std::getline(std::cin, contact_index);
		if (std::cin.eof())
			return (-1);
		index = std::stoi(contact_index);
		if (index < 1 || index > 8)
		{
			std::cout << "Contact not found... Damn it :(" << std::endl;
			continue ;
		}
		return (index - 1);
	}
	return (-1);
}

void	PhoneBook::search( void )
{
	int	index;

	this->show_contacts();
	index = this->get_contact_index();
	if (index == -1)
		return ;
	if (this->contacts[index].is_empty())
		std::cout << "This contact is empty :)" << std::endl;
	else
		std::cout << this->contacts[index].info();
}

void	PhoneBook::add( void )
{
	this->contacts[this->actual_index].set_first_name();
	this->contacts[this->actual_index].set_last_name();
	this->contacts[this->actual_index].set_nickname();
	this->contacts[this->actual_index].set_phone_number();
	this->contacts[this->actual_index].set_darkest_secret();
	this->contacts[this->actual_index].save();
	if (this->actual_index < 7)
		this->actual_index++;
}
