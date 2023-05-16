/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:17:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/15 21:27:15 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void )
{
	this->actual_index = 0;
}
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

int PhoneBook::atoi(std::string str)
{
	int		num = 0;
	int		sign = 1;
	size_t	i = 0;

	// Skip whitespace
	while (i < str.length() && isspace(str[i]))
		i++;

	// Handle sign
	if (i < str.length() && (str[i] == '+' || str[i] == '-'))
		sign = (str[i++] == '-') ? -1 : 1;

	// Convert digits
	while (i < str.length() && isdigit(str[i]))
		num = num * 10 + (str[i++] - '0');
	return num * sign;
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
		index = this->atoi(contact_index);
		if (index < 1 || index > 8)
		{
			std::cout << "\033[31mContact not found... Damn it :(\033[0m" << std::endl;
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
		std::cout << "\033[31mThis contact is empty :)\033[0m" << std::endl;
	else
		std::cout << this->contacts[index].info();
}

void	PhoneBook::add( void )
{
	std::cout << std::endl;
	this->contacts[this->actual_index].set_first_name();
	this->contacts[this->actual_index].set_last_name();
	this->contacts[this->actual_index].set_nickname();
	this->contacts[this->actual_index].set_phone_number();
	this->contacts[this->actual_index].set_darkest_secret();
	this->contacts[this->actual_index].save();
	if (this->actual_index < 7)
		this->actual_index++;
}

void	PhoneBook::whisper(std::string message)
{
	std::cout << message << std::endl;
}

bool	PhoneBook::invalid_input(void)
{
	return std::cin.eof();
}

void	PhoneBook::show_menu( void )
{
	std::cout << std::endl;
	std::cout << "Options: ";
	std::cout << "[ " << "ADD" << " ]";
	std::cout << "[ " << "SEARCH" << " ]";
	std::cout << "[ " << "EXIT" << " ]";
	std::cout << std::endl;
	std::cout << "Op: ";
}

int	PhoneBook::get_option( void )
{
	std::string	option;

	this->show_menu();
	std::getline(std::cin, option);
	if (!option.compare("ADD"))
		return (0);
	if (!option.compare("SEARCH"))
		return (1);
	if (!option.compare("EXIT"))
		return (2);
	if (this->invalid_input())
		return (3);
	return (4);
}
