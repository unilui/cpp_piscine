/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:50:50 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 18:55:27 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void )
{
	std::cout << "ScavTrap default constructor called" << std::endl;
    this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{ 
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 50;
}

ScavTrap::ScavTrap(ScavTrap const &scavtrap_to_copy) : ClapTrap()
{
    *this = scavtrap_to_copy;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &scavtrap_to_copy)
{
	if (this == &scavtrap_to_copy)
		return (*this);

    this->name = scavtrap_to_copy.get_name();
    this->hit_points = scavtrap_to_copy.get_hit_points();
    this->energy_points = scavtrap_to_copy.get_energy_points();
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTrap destructor called" << std::endl; 
}

void    ScavTrap::attack(const std::string& target)
{
    std::cout << "Scavtrap " << this->name;
    
    if (!this->energy_points)
    {
        std::cout << " doesn't have enough energy :/" << std::endl;
        return ;
    }
    
    if (!this->hit_points)
    {
        std::cout << " doesn't have enough hit points :/" << std::endl;
        return ;
    }

    std::cout << " Attacks ";
    std::cout << target;
    std::cout << " causing ";
    std::cout << this->attack_damage;
    std::cout << " points of damage!";
    std::cout << std::endl;

    this->energy_points -= 1;
}

void    ScavTrap::guardGate( void )
{
    this->guarding_guate = !this->guarding_guate;

    if (this->guarding_guate)
        std::cout << this->name + " is now guarding the gate!" << std::endl;
    else
        std::cout << this->name + " is no longer guarding a gate" << std::endl;
}
