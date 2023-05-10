/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:15:12 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/09 22:30:12 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) { return ; }
Contact::~Contact(void) { return ; }


void	Contact::set_first_name(std::string new_first_name)
{
	this->first_name = new_first_name;
}

void	Contact::set_last_name(std::string new_last_name)
{
	this->last_name = new_last_name;
}

void	Contact::set_phone_number(std::string new_phone_number)
{
	this->phone_number = new_phone_number;
}

void	Contact::set_nickname(std::string new_nickname)
{
	this->nickname = new_nickname;
}

void	Contact::set_darkest_secret(std::string new_darkest_secret)
{
	this->darkest_secret = new_darkest_secret;
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
