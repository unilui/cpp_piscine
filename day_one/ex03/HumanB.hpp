/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:17:01 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/19 02:53:15 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string		name;
	Weapon			*weapon;

public:
	HumanB(std::string name);
	~HumanB( void );

	void	attack(void);
	void	setWeapon(Weapon& weapon);
};

#endif
