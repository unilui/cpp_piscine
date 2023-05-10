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
#include "Contact.hpp"

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
	Contact		teste;

	display.warning();
	teste.set_first_name("Felipe");
	teste.set_last_name("Camargo");
	teste.set_nickname("Lipe");
	teste.set_phone_number("7070-7070");
	teste.set_darkest_secret("Weeeeeeeeee");
	std::cout << teste.summary();
	std::cout << teste.info();
	//while(display.big_enough())
	//{
	//	switch (display.get_option(options, 3)) {
	//		case ADD:
	//			display.whisper("The customer is always wrong");
	//			break;
	//		case SEARCH:
	//			display.whisper("The chairman is an asshole");
	//			break;
	//		case EXIT:
	//			display.whisper("Not sorry to see you go :)");
	//			break;
	//		case INVALID:
	//			display.whisper("Not sorry to see you go :)");
	//			return (1);
	//			break;
	//		default:
	//			display.whisper("You're really stupid :)");
	//	}
	//}
	return (0);
}
