/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:58:34 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 13:29:09 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
    :   name(name),
        hit_points(10),
        energy_points(10),
        attack_damage(0)
{ 
    std::cout << name << " default constructor called" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap& claptrap_to_copy)
{
    *this = claptrap_to_copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& claptrap_to_copy)
{
	if (this == &claptrap_to_copy)
		return (*this);

    this->attack_damage = claptrap_to_copy.get_attack_damage();
    this->energy_points = claptrap_to_copy.get_energy_points();
    this->hit_points = claptrap_to_copy.get_hit_points();

	return (*this);
}

ClapTrap::~ClapTrap( void )
{
    std::cout << name << " Destructor called" << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << this->name;
    
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

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->name;
    std::cout << " takes ";
    std::cout << amount;
    std::cout << " points of damage!";
    std::cout << std::endl;
    
    if (!this->hit_points)
        return;
    
    this->hit_points -= amount;
    
    if (this->hit_points < 0)
        this->hit_points = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << this->name;

    if (!this->energy_points)
    {
        std::cout << " doesn't have enough energy :/" << std::endl;
        return ;
    }

    std::cout << " healed ";
    std::cout << amount;
    std::cout << " points";
    std::cout << std::endl;
    
    this->hit_points += amount;
    this->energy_points -= 1;
}

int	ClapTrap::get_hit_points(void) const
{
    return (this->hit_points);
}

int	ClapTrap::get_energy_points(void) const
{
    return (this->energy_points);
}

int	ClapTrap::get_attack_damage(void) const
{
    return (this->attack_damage);
}