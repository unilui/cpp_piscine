/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:50:44 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 18:51:51 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap 
{
private:
	bool	guarding_guate;

public:
	ScavTrap( void );
    ScavTrap(const std::string name);
	ScavTrap(ScavTrap const &ScavTrap_to_copy);
	ScavTrap& operator=(ScavTrap const &ScavTrap_to_copy);
	~ScavTrap(void);

	void attack(const std::string& target);
	void guardGate( void );
};

#endif