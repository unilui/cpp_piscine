/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 23:46:04 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 01:14:56 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*string_ptr = &string;
	std::string	&string_ref = string;

	std::cout << "Memory address of string: " << &string << std::endl;
	std::cout << "Memory address of pointer to string: " << &string_ptr << std::endl;
	std::cout << "Memory address of reference to string: " << &string_ref << std::endl;

	std::cout << "\n";
	std::cout << "String:" << std::endl;
	std::cout << string << std::endl;

	std::cout << "\n";
	std::cout << "String by pointer:" << std::endl;
	std::cout << *string_ptr << std::endl;

	std::cout << "\n";
	std::cout << "String by reference:" << std::endl;
	std::cout << string_ref << std::endl;
	return (0);
}
