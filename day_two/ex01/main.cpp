/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:48:38 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/17 22:52:29 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main( void )
{
	int		number_of_zombies = 5;
	Zombie	*horde;

	horde = zombieHorde(number_of_zombies, "Pedro");
	for (int zombie = 0; zombie < number_of_zombies; zombie++)
		horde[zombie].announce();

	return (0);
}
