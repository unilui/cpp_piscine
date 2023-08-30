/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:53:31 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/10 21:09:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : value(0)
{
}

Fixed::Fixed(const Fixed& fixed_to_copy)
{
	*this = fixed_to_copy;
}

Fixed& Fixed::operator=(const Fixed& fixed_to_copy)
{
	if (this == &fixed_to_copy)
		return (*this);

	this->value = fixed_to_copy.getRawBits();

	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_to_print)
{
	os << fixed_to_print.toFloat();
	return (os);
}

Fixed::Fixed(const int value) : value(0)
{
	if (value > this->_max_limit)
		std::cerr << "Error: passed value ["<< value <<"] is greater than the max representable number" << std::endl;
	else if (value < this->_min_limit * -1)
		std::cerr << "Error: passed value ["<< value <<"] is lower than the min representable number" << std::endl;
	else
		this->value = value << 8;
}

Fixed::Fixed(const float value)
{
	this->value = (int)roundf(value * (1 << Fixed::point_position));
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (1 << Fixed::point_position));
}

int	Fixed::toInt(void) const
{
	return (this->value / (1 << Fixed::point_position));
}

bool	Fixed::operator>(Fixed const &arg) const
{
	return (this->toFloat() > arg.toFloat());
}
bool	Fixed::operator<(Fixed const &arg) const
{
	return (this->toFloat() < arg.toFloat());
}

bool	Fixed::operator>=(Fixed const &arg) const
{
	return (this->toFloat() >= arg.toFloat());
}

bool	Fixed::operator<=(Fixed const &arg) const
{
	return (this->toFloat() <= arg.toFloat());
}

bool	Fixed::operator==(Fixed const &arg) const
{
	return (this->getRawBits() == arg.getRawBits());
}

bool	Fixed::operator!=(Fixed const &arg) const
{
	return (this->getRawBits() != arg.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &arg)
{
	return (this->toFloat() + arg.toFloat());
}

Fixed	Fixed::operator-(Fixed const &arg)
{
	return (this->toFloat() - arg.toFloat());
}

Fixed	Fixed::operator*(Fixed const &arg)
{
	return (this->toFloat() * arg.toFloat());
}

Fixed	Fixed::operator/(Fixed const &arg)
{
	return (this->toFloat() / arg.toFloat());
}

Fixed	Fixed::operator++(int)
{
	Fixed rv(*this);

	this->value++;
	return rv;
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed rv(*this);

	this->value--;
	return rv;
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return *this;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return a;
	return b;
}
