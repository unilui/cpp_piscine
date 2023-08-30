/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:38:13 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 16:48:45 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_HPP
# define MATH_HPP

template< typename T>
void	swap(T &x, T &y)
{
	T tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template< typename T>
T	&min(T &x, T &y)
{
	return ( x < y ? x : y);
}

template< typename T>
T	&max(T &x, T &y)
{
	return ( x > y ? x : y);
}

#endif
