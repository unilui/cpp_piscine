/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:20:06 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/23 19:37:38 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "File.hpp"

bool	valid_args(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Required three arguments:" << std::endl;
		std::cout << "<filename> <str_to_replace> <target_str>" << std::endl;
		return false;
	}
	for (int i = 0; i < 4; i++)
	{
		if (*argv[i] == '\0')
		{
			std::cout << "No empty argument allowed :/" << std::endl;
			return false;
		}
	}
	return true;
}

int	main(int argc, char **argv)
{
	if (!valid_args(argc, argv))
		return (1);

	std::string	file_path(argv[1]);
	std::string	str_to_replace(argv[2]);
	std::string	target_str(argv[3]);
	File		file(file_path);

	if (!file.loaded())
	{
		std::cout << "Couldn't open " << argv[1] << std::endl;
		return (2);
	}

	file.replace(str_to_replace, target_str);

	if (!file.save(file_path.append(".replace")))
	{
		std::cout << "Couldn't save " << argv[1] << std::endl;
		return (3);
	}
	return (0);
}
