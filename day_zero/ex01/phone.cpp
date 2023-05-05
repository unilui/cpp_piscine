/* ************************************************************************** */
/* */
/*  :::::::::::*/
/*phone.cpp:+::+: :+:*/
/* +:+ +:++:+  */
/*By: lufelip2 <lufelip2@student.42sp.org.br> +#+  +:+ +#+  */
/*+#+#+#+#+#++#+  */
/*Created: 2023/04/30 17:30:13 by lufelip2 #+# #+# */
/*Updated: 2023/04/30 21:23:22 by lufelip2###########.fr */
/* */
/* ************************************************************************** */

#include <string>
#include <iomanip>
#include <iostream>
#include "Display.hpp"

int	main(void)
{
	std::string	option;
	Display		display;

	display.warning();
	while(true)
	{
		std::cin >> option;
		if (std::cin.eof())
		{
			std::cout << "Are you idiot?" << std::endl;
			return (1);
		}
		if (!option.compare("ADD"))
			std::cout << "The customer is always wrong" << std::endl;
		else if (!option.compare("SEARCH"))
			std::cout << "The chairman is an asshole" << std::endl;
		else if (!option.compare("EXIT"))
		{
			std::cout << "Not sorry to see you go :)" << std::endl;
			return (0);
		}
		else
			std::cout << "You're really stupid :)" << std::endl;
	}
	return (0);
}
