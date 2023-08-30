/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:19 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:17:04 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{ 
	std::cout << "Dog default constructor called" << std::endl; 
}

Dog::Dog(Dog const &dog_to_copy) : Animal(dog_to_copy.getType())
{
	*this = dog_to_copy;
}

Dog& Dog::operator=(Dog const &Dog_to_copy)
{
	if (this == &Dog_to_copy)
		return (*this);
	return (*this);
}

Dog::~Dog( void )
{ 
	std::cout << "Dog default destructor called" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "A A AUUUUUUUUUUUUUUUUUUUUUUUUUUU" << std::endl;
}