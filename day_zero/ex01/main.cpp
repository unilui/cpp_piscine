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

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	while(true)
	{
		if (phonebook.invalid_input())
		{
			phonebook.whisper("\nGod knows I tried :)");
			return (1);
		}
		switch (phonebook.get_option()) {
			case _PHONE_ADD_:
				phonebook.add();
				break;
			case _PHONE_SEARCH_:
				phonebook.search();
				break;
			case _PHONE_EXIT_:
				phonebook.whisper("Not sorry to see you go :)");
				return (0);
				break;
			case _PHONE_INVALID_:
				phonebook.whisper("\nGod knows I tried :)");
				return (1);
				break;
			default:
				phonebook.whisper("Did you read the fucking options? :)");
		}
	}
	return (0);
}
