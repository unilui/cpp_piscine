/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:53:46 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/08 21:38:53 by lufelip2         ###   ########.fr       */
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

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed_to_print);

#endif
