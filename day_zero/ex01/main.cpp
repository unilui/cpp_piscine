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

	while(display.big_enough())
	{
		if (display.invalid_input())
		{
			display.whisper("\nGod knows I tried :)");
			return (1);
		}
		switch (display.get_option(options, 3)) {
			case ADD:
				phonebook.add();
				break;
			case SEARCH:
				phonebook.search();
				break;
			case EXIT:
				display.whisper("Not sorry to see you go :)");
				return (0);
				break;
			case INVALID:
				display.whisper("\nGod knows I tried :)");
				return (1);
				break;
			default:
				display.whisper("Did you read the fucking options? :)");
		}
	}
	return (0);
}
