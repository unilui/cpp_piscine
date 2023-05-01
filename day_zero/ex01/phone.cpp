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
	"██░░░░░░░░░░░░░░░░█ 05 █░░░░░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░░░██",
	"██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██",
	"██████████████████████████████████████████"
};

void	put_padding(int size)
{
	for (int i = 0; i < size; i++)
		std::cout << ' ';
}

void	header(void)
{
	winsize size;
 	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
 	int width = size.ws_col;
	int height = size.ws_row;

	for (int i = 0; i < 16; i++)
	{
		put_padding((width / 2) - (warning_symbol[i].length() / 3) / 2);
		std::cout << warning_symbol[i] << std::endl;
	}
	put_padding((width / 2) - 21);
	std::cout << "██░░░░░░░░░░░░░░░░█" << " 05 " << "█░░░░░░░░░░░░░░░░██" << std::endl;
	for (int i = 17; i < 20; i++)
	{
		put_padding((width / 2) - (warning_symbol[i].length() / 3) / 2);
		std::cout << warning_symbol[i] << std::endl;
	}
}

int	main(void)
{
	std::string	option;

	header();	while(true)
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
			std::cout << "Not sorry to see you go :)" << std::endl;
		else
			std::cout << "You're really stupid :)" << std::endl;
	}
	return (0);
}
ṕoiuytr
