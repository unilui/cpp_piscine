/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:17:09 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/19 02:43:13 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string		name;
	Weapon			*weapon;

public:
	HumanA(std::string name, Weapon& Weapon);
	~HumanA( void );

	void	attack(void);
};

#endif
