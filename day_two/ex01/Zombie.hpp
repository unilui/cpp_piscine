/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:12:40 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/17 22:46:30 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string	name;

public:
	Zombie(std::string name);
	~Zombie( void );
	Zombie( void );

	void	announce( void );
	void	set_name( std::string name );
};

#endif
