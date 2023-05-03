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

#include <iostream>
#include <iomanip>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

std::string	warning_symbol[] = {
	"██",
	"██░░██",
	"██░░░░░░██",
	"██░░░░░░░░░░██",
	"██░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░██",
	"██░░░░░░██████░░░░░░██",
	"██░░░░░░██████░░░░░░██",
	"██░░░░░░░░██████░░░░░░░░██",
	"██░░░░░░░░██████░░░░░░░░██",
	"██░░░░░░░░░░██████░░░░░░░░░░██",
	"██░░░░░░░░░░░░██████░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░██████░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██",
	"██████████████████████████████████████████"
	"\n",
	"The phonebook can be very impatient!\n",
	"They didn't want to be written in C++\n",
	"They prefer Golang :)"
};

void	put_padding(int size)
{
	for (int i = 0; i < size; i++)
		std::cout << ' ';
}

void	warning(void)
{
	winsize size;
 	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
 	int width = size.ws_col;
	int height = size.ws_row;

	int line = 0;
	int time = 5;
	while (time > 0)
	{
		std::cout << "\033c";
		std::cout << "\033[38;2;255;0;0m";
		while (line < 16)
		{
			put_padding((width / 2) - (warning_symbol[line].length() / 3) / 2);
			std::cout << warning_symbol[line++] << std::endl;
		}
		put_padding((width / 2) - 21);
		std::cout << "██░░░░░░░░░░░░░░░░█ 0" << time-- << " █░░░░░░░░░░░░░░░░██" << std::endl;
		while (line < 19)
		{
			put_padding((width / 2) - (warning_symbol[line].length() / 3) / 2);
			std::cout << warning_symbol[line++] << std::endl;
		}
		while(line < 23)
		{
			put_padding((width / 2) - (warning_symbol[line].length() / 2));
			std::cout << warning_symbol[line++] << std::endl;
		}
		line = 0;
		sleep(1);
	}
	std::cout << "\033c";
}

int	main(void)
{
	std::string	option;

	warning();
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
