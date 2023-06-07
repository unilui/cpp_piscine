/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:17:07 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/19 02:45:22 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon)
:	name(name), weapon(&weapon)
{ return ; };

HumanA::~HumanA( void ) { return ; };

void	HumanA::attack(void)
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << this->weapon->getType() << std::endl;
}
