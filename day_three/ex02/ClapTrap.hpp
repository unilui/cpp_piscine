/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:52:38 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 17:57:13 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string			name;
	int                 hit_points;
	int                 energy_points;
	int                 attack_damage;

public:
	ClapTrap( void );
	ClapTrap(const std::string name);
	ClapTrap(ClapTrap const &claptrap_to_copy);
	ClapTrap& operator=(const ClapTrap& claptrap_to_copy);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string	get_name( void ) const;
	int			get_hit_points( void ) const;
	int			get_energy_points( void ) const;
};

#endif