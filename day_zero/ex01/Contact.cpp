/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:15:12 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/13 19:06:06 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) { return ; }
Contact::~Contact(void) { return ; }

void	Contact::set_first_name( void )
{
	if (std::cin.eof())
		return ;
// Check if is only letters
	std::string first_name;

	while (true)
	{
		std::cout << "First name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
			return ;
		if (first_name.length() > 0)
			break ;
	}
	this->first_name = first_name;
}

void	Contact::set_last_name( void )
{
	if (std::cin.eof())
		return ;

	std::string last_name;

	while (true)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
			return ;
		if (last_name.length() > 0)
			break ;
	}
	this->last_name = last_name;
}

void	Contact::set_phone_number( void )
{
	if (std::cin.eof())
		return ;

	std::string phone_number;

	while (true)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
			return ;
		if (phone_number.length() > 0)
			break ;
	}
	this->phone_number = phone_number;
}

void	Contact::set_nickname( void )
{
	if (std::cin.eof())
		return ;

	std::string nickname;

	while (true)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return ;
		if (nickname.length() > 0)
			break ;
	}
	this->nickname = nickname;
}

void	Contact::set_darkest_secret( void )
{
	if (std::cin.eof())
		return ;

	std::string darkest_secret;

	while (true)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, darkest_secret);
		if (std::cin.eof())
			return ;
		if (darkest_secret.length() > 0)
			break ;
	}
	this->darkest_secret = darkest_secret;
}

std::string	Contact::truncate(std::string string)
{
	if (string.length() > 10)
	{
		string = string.substr(0, 10);
		string[9] = '.';
	}
	return (string);
}

bool	Contact::is_empty(void)
{
	return (this->empty);
}

void	Contact::save(void)
{
	this->empty = false;
}

std::string	Contact::summary(void)
{
	std::stringstream	buffer;
	buffer << "|" << std::setw(10) << std::right << this->truncate(this->first_name);
	buffer << "|" << std::setw(10) << std::right << this->truncate(this->last_name);
	buffer << "|" << std::setw(10) << std::right << this->truncate(this->nickname);
	buffer << "|" << std::endl;
	return (buffer.str());
}

std::string	Contact::info(void)
{
	std::stringstream	buffer;
	buffer << "First name: " << this->first_name << std::endl;
	buffer << "Last name: " << this->last_name << std::endl;
	buffer << "Nickname: " << this->nickname << std::endl;
	buffer << "Phone number: " << this->phone_number << std::endl;
	buffer << "Darkest secret: " << this->darkest_secret << std::endl;
	return (buffer.str());
}
