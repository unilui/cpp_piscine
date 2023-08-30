/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:38:13 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 18:50:23 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_HPP
# define MATH_HPP

#include <iostream>

template< typename T>
void	iter(T *addres, size_t length, void (*function_to_apply)(T&))
{
	for (size_t i = 0; i  < length; i++)
		function_to_apply(addres[i]);
}

#endif
