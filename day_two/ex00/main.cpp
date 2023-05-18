/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 19:16:33 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/17 22:01:25 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main( void )
{
	std::string	friends[5] = {"Renato", "Davy", "Renan", "Aline", "Luanny"};
	Zombie		*heap_zombie;
	int			chosen_friend;

	// Seed the random number generator
	std::srand(std::time(0));

	// Generate a random number between 0 and 4
	chosen_friend = std::rand() % 5;

	std::cout << "\n\nTESTING HEAP ZOMBIE:\n\n";
	heap_zombie = newZombie(friends[chosen_friend]);
	heap_zombie->announce();
	delete heap_zombie;

	chosen_friend = std::rand() % 5;

	std::cout << "\n\nTESTING STACK ZOMBIE:\n\n";
	randomChump(friends[chosen_friend]);
	return (0);
}
