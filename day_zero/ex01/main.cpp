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
#include "PhoneBook.hpp"

#define ADD		0
#define SEARCH	1
#define EXIT	2
#define INVALID 3

std::string	options[] = {
	"ADD",
	"SEARCH",
	"EXIT"
};

int	main(void)
{
	Display		display;
	PhoneBook	phonebook;

	phonebook.search();
	while(display.big_enough())
	{
		switch (display.get_option(options, 3)) {
			case ADD:
				display.whisper("The customer is always wrong");
				break;
			case SEARCH:
				display.whisper("The chairman is an asshole");
				break;
			case EXIT:
				display.whisper("Not sorry to see you go :)");
				break;
			case INVALID:
				display.whisper("Not sorry to see you go :)");
				return (1);
				break;
			default:
				display.whisper("You're really stupid :)");
		}
	}
	return (0);
}
