/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:50:50 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 13:37:49 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void )
{
	std::cout << "FragTrap default constructor called" << std::endl;
    this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	return ;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{ 
    std::cout << "FragTrap default constructor called" << std::endl;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &fragtrap_to_copy) : ClapTrap()
{
    *this = fragtrap_to_copy;
}

FragTrap& FragTrap::operator=(FragTrap const &fragtrap_to_copy)
{
	if (this == &fragtrap_to_copy)
		return (*this);

    this->name = fragtrap_to_copy.get_name();
    this->hit_points = fragtrap_to_copy.get_hit_points();
    this->energy_points = fragtrap_to_copy.get_energy_points();
	return (*this);
}

FragTrap::~FragTrap( void )
{
    std::cout << "FragTrap destructor called" << std::endl; 
}

void    FragTrap::attack(const std::string& target)
{
    std::cout << "FragTrap " << this->name;
    
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

void    FragTrap::high_fives_guys(void)
{
	std::cout << "High five guys!" << std::endl;
}