/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:53:31 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/07 20:55:20 by lufelip2         ###   ########.fr       */
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

Fixed& Fixed::operator=(const Fixed& fixed_to_copy)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &fixed_to_copy)
		return (*this);

	this->value = fixed_to_copy.getRawBits();

	return (*this);
}

Fixed::Fixed(const int value) : value(0)
{
	std::cout << "Int constructor called" << std::endl;

	if (value > this->_max_limit)
		std::cerr << "Error: passed value ["<< value <<"] is greater than the max representable number" << std::endl;
	else if (value < this->_min_limit * -1)
		std::cerr << "Error: passed value ["<< value <<"] is lower than the min representable number" << std::endl;
	else
		this->value = value << 8;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
