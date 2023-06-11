/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:53:46 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/10 21:08:31 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{

private:
	static const int	point_position = 8;
	int					value;
	static const int	_max_limit = 0x7fffff;
	static const int	_min_limit = 0x800000;




public:
	Fixed(void);
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& fixed_to_copy);
	Fixed& operator=(const Fixed& fixed_to_copy);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// comparison: >, <, >=, <=, == !=
	bool	operator>(Fixed const &toCompare) const;
	bool	operator<(Fixed const &toCompare) const;
	bool	operator>=(Fixed const &toCompare) const;
	bool	operator<=(Fixed const &toCompare) const;
	bool	operator==(Fixed const &toCompare) const;
	bool	operator!=(Fixed const &toCompare) const;

	// arithmetic: +, -, *, /
	Fixed	operator+(Fixed const &toOperate);
	Fixed	operator-(Fixed const &toOperate);
	Fixed	operator*(Fixed const &toOperate);
	Fixed	operator/(Fixed const &toOperate);

	// in(de)crement: ++ --;
	Fixed	operator++(int);
	Fixed	&operator++(void);
	Fixed	operator--(int);
	Fixed	&operator--(void);

	// min maxes
	static const Fixed&	min(Fixed const &a, Fixed const &b);
	static const Fixed&	max(Fixed const &a, Fixed const &b);
	static Fixed	&min(Fixed &a, Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_to_print);

#endif
