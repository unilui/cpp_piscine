/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:56:51 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:56:52 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{ 
	std::cout << "WrongCat default constructor called" << std::endl;
}
		
WrongCat::WrongCat(WrongCat const &wrong_cat_to_copy)
    : WrongAnimal(wrong_cat_to_copy.getType())
{
	*this = wrong_cat_to_copy;
}

WrongCat	&WrongCat::operator=(WrongCat const &wrong_cat_to_copy)
{
	if (this == &wrong_cat_to_copy)
		return (*this);
	return (*this);
}

WrongCat::~WrongCat( void )
{ 
	std::cout << "WrongCat default destructor called" << std::endl;
}

void  WrongCat::makeSound( void ) const
{
	std::cout << "Miau Miau MIAAAUUUUU!!" << std::endl;
}