/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:37:26 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 18:50:38 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

template< typename T>
void	print_it(T &data)
{
	std::cout << data << std::endl;
}

template< typename T>
void	increase_it(T &data)
{
	data++;
}

int main( void )
{
	std::cout << "Testing int array" << std::endl;
	int	teste[4];

	teste[0] = 1;
	teste[1] = 2;
	teste[2] = 3;
	teste[3] = 4;

	::iter(teste, 4, &print_it<int>);

	std::cout << "Testing char array" << std::endl;
	char	teste1[4];

	teste1[0] = 42;
	teste1[1] = 43;
	teste1[2] = 44;
	teste1[3] = 45;

	::iter(teste1, 4, &print_it<char>);

	std::cout << "Testing float array" << std::endl;
	float	teste2[4];

	teste2[0] = 42.5f;
	teste2[1] = 43.5f;
	teste2[2] = 44.5f;
	teste2[3] = 45.5f;

	::iter(teste2, 4, &print_it<float>);

	std::cout << "Testing increasing array" << std::endl;
	float	teste3[4];

	teste3[0] = 42.5f;
	teste3[1] = 43.5f;
	teste3[2] = 44.5f;
	teste3[3] = 45.5f;

	::iter(teste3, 4, &print_it<float>);
	::iter(teste3, 4, &increase_it<float>);
	std::cout << "---------------------------" << std::endl;
	::iter(teste3, 4, &print_it<float>);
	return 0;
}
