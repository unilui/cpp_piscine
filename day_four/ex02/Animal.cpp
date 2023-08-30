/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:07 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 19:14:34 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Unknown")
{ 
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const type) : type(type) 
{
	std::cout << type << " type animal default constructor called" << std::endl;
} 

Animal::Animal(Animal const &animal_to_copy)
{
	*this = animal_to_copy;
}

Animal& Animal::operator=(Animal const &animal_to_copy)
{
	if (this == &animal_to_copy)
		return (*this);
	
	this->set_brain(animal_to_copy.get_brain());
	return (*this);
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}

Animal::~Animal( void ) 
{
	std::cout << this->type << " type animal default destructor called" << std::endl;
}