/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:16:52 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/19 02:23:58 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
	: type(type)
{ return ; };
Weapon::~Weapon( void ) { return ; };

const std::string&	Weapon::getType( void )
{
	const std::string	&ref = this->type;
	return (ref);
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}
