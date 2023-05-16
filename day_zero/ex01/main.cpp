/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:10:07 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/15 21:35:40 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;

	while(true)
	{
		if (phonebook.invalid_input())
		{
			phonebook.whisper("\n\033[33mGod knows I tried :)\033[0m");
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
				phonebook.whisper("\033[33mNot sorry to see you go :)\033[0m");
				return (0);
				break;
			case _PHONE_INVALID_:
				phonebook.whisper("\n\033[33mGod knows I tried :)\033[0m");
				return (1);
				break;
			default:
				phonebook.whisper("\033[33mDid you read the fucking options? :)\033[0m");
		}
	}
	return (0);
}
