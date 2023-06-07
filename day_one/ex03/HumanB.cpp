/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:17:04 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/19 02:55:58 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
:	name(name), weapon(NULL)
{ return ; };

HumanB::~HumanB( void ) { return ; };

void	HumanB::attack(void)
{
	std::cout << this->name;
	if (!this->weapon)
	{
		std::cout << " has no weapon :/" << std::endl;
		return ;
	}
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}
