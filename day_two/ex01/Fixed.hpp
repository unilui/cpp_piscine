/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:53:46 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/07 20:25:51 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{

private:
	static const int	point_position = 8;
	int					value;
	const int			_max_limit = 0x7fffff;
	const int			_min_limit = 0x800000;

public:
	Fixed(void);
	Fixed(const Fixed& fixed_to_copy);
	Fixed(const int value);
	Fixed& operator=(const Fixed& fixed_to_copy);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
