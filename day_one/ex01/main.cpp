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
#include <cstdlib>
#include <ctime>

Zombie* zombieHorde( int N, std::string name );

int	main( void )
{
	std::string	friends[5] = {"Renato", "Davy", "Renan", "Aline", "Luanny"};
	int			number_of_zombies = 5;
	Zombie		*horde;
	int			chosen_friend;

	// Seed the random number generator
	std::srand(std::time(0));

	// Generate a random number between 0 and 4
	chosen_friend = std::rand() % 5;

	horde = zombieHorde(number_of_zombies, friends[chosen_friend]);
	for (int zombie = 0; zombie < number_of_zombies; zombie++)
		horde[zombie].announce();
	
	delete [] horde;
	return (0);
}
