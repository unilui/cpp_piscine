/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:29:40 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/23 19:29:59 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class File
{
private:
	std::string	file_content;
	bool		file_loaded;

public:
	File(std::string file_path);
	~File(void);

	void	replace(std::string str, std::string target, int pos = 0);
	bool	save(std::string file_path);
	bool	loaded(void);
};

#endif
