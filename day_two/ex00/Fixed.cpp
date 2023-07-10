/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 04:45:01 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/20 18:06:29 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed_to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed_to_copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
} 

Fixed& Fixed::operator=(const Fixed& fixed_to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &fixed_to_copy)
		return (*this);

	this->value = fixed_to_copy.getRawBits();

	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
