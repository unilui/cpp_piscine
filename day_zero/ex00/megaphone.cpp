/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 05:13:18 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/16 21:27:29 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

char	*str_to_upper(char *str)
{
	for (int i = 0; str[i]; i++)
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	char	default_message[] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (argc > 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			argv[i] = str_to_upper(argv[i]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	else
		std::cout << default_message << std::endl;
	return (0);
}
int main() {// Example C-style string

    std::string cppString(cString); // Convert C-string to std::string

    std::cout << "C++ string: " << cppString << std::endl;

    return 0;
}
