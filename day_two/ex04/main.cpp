/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:20:06 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/19 20:04:17 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "File.hpp"

bool	valid_args(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Required three arguments:" << std::endl;
		std::cout << "<filename> <str_to_replace> <str>" << std::endl;
		return false;
	}
	return true;
}

int	main(int argc, char **argv)
{
	if (!valid_args(argc, argv)) return ;
	File	file("teste.txt");

	file.replace("lindo", "");
	file.save("teste.replace");
	return (0);
}
