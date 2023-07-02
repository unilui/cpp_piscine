/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:11 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:17:35 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{ 
	std::cout << "Cat default constructor called" << std::endl;
}
		
Cat::Cat(Cat const &cat_to_copy) : Animal(cat_to_copy.getType())
{
	*this = cat_to_copy;
}

Cat	&Cat::operator=(Cat const &Cat_to_copy)
{
	if (this == &Cat_to_copy)
		return (*this);
	return (*this);
}

Cat::~Cat( void )
{ 
	std::cout << "Cat default destructor called" << std::endl;
}

void  Cat::makeSound( void ) const
{
	std::cout << "Miau Miau MIAAAUUUUU!!" << std::endl;
}