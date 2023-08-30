/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 16:52:38 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 13:24:39 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
private:
	const std::string   name;
	int                 hit_points;
	int                 energy_points;
	int                 attack_damage;

public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap& claptrap_to_copy);
	ClapTrap& operator=(const ClapTrap& claptrap_to_copy);
	~ClapTrap(void);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	int	get_hit_points(void) const;
	int	get_energy_points(void) const;
	int	get_attack_damage(void) const;
};

#endif