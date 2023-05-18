/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:14:08 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/17 23:01:26 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
	this->name = "Snow";
}

Zombie::~Zombie( void )
{
	std::cout << this->name << " is dead :(" << std::endl;
}

Zombie::Zombie( std::string name ) : name(name) { return ; }

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name( std::string name )
{
	this->name = name;
}
