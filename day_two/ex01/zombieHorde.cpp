/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:26:44 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/17 22:48:07 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.cpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde = static_cast<Zombie*>(operator new[](N * sizeof(Zombie)));

	horde = static_cast<Zombie*>(operator new[](N * sizeof(Zombie)));
	for (int zombie = 0; zombie < N; zombie++)
		new(&horde[zombie]) Zombie(name);
	return (horde);
}
