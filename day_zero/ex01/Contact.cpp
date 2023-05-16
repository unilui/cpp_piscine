/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:15:12 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/15 21:33:38 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->empty = true;
}
Contact::~Contact(void) { return ; }

bool Contact::is_alpha(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!std::isalpha(str[i]))
			return false;
	}
	return true;
}

bool Contact::is_numeric(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool Contact::is_alpha_numeric(std::string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (!std::isdigit(str[i]) && !std::isalpha(str[i]))
			return false;
	}
	return true;
}

void	Contact::set_first_name( void )
{
	std::string first_name;

	if (std::cin.eof())
		return ;
	while (true)
	{
		std::cout << "First name: ";
		std::getline(std::cin, first_name);
		if (std::cin.eof())
			return ;
		if (!this->is_alpha(first_name))
		{
			std::cout << "\033[31mOnly alphabetic characters, please :)\033[0m\n\n";
			continue ;
		}
		if (first_name.length() > 0)
			break ;
	}
	this->first_name = first_name;
}

void	Contact::set_last_name( void )
{
	std::string last_name;

	if (std::cin.eof())
		return ;
	while (true)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, last_name);
		if (std::cin.eof())
			return ;
		if (!this->is_alpha(last_name))
		{
			std::cout << "\033[31mOnly alphabetic characters, please :)\033[0m\n\n";
			continue ;
		}
		if (last_name.length() > 0)
			break ;
	}
	this->last_name = last_name;
}

void	Contact::set_phone_number( void )
{
	std::string phone_number;

	if (std::cin.eof())
		return ;
	while (true)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, phone_number);
		if (std::cin.eof())
			return ;
		if (!this->is_numeric(phone_number))
		{
			std::cout << "\033[31mOnly numeric characters, please :)\033[0m\n\n";
			continue ;
		}
		if (phone_number.length() > 0)
			break ;
	}
	this->phone_number = phone_number;
}

void	Contact::set_nickname( void )
{
	std::string nickname;

	if (std::cin.eof())
		return ;
	while (true)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, nickname);
		if (std::cin.eof())
			return ;
		if (!this->is_alpha(nickname))
		{
			std::cout << "\033[31mOnly alphabetic characters, please :)\033[0m\n\n";
			continue ;
		}
		if (nickname.length() > 0)
			break ;
	}
	this->nickname = nickname;
}

void	Contact::set_darkest_secret( void )
{
	std::string darkest_secret;

	if (std::cin.eof())
		return ;
	while (true)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, darkest_secret);
		if (std::cin.eof())
			return ;
		if (!this->is_alpha_numeric(darkest_secret))
		{
			std::cout << "\033[31mOnly alphanumeric characters, please :)\033[0m\n\n";
			continue ;
		}
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
