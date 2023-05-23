/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 03:29:42 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/19 06:11:25 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::~File( void ) { return ; };

File::File(std::string file_path) : file_loaded(false)
{
	std::ifstream		input_file(file_path.c_str());
	std::stringstream	buffer;

	if (!input_file.is_open()) return ;

	buffer << input_file.rdbuf();
	this->file_content = buffer.str();

	input_file.close();
	this->file_loaded = true;
};

void	File::replace(std::string str, std::string target)
{
	if (str.empty()) return ;

	std::string	new_line;
	std::size_t	found;

	found = this->file_content.find(str);
	if (found == std::string::npos) return ;

	if (found > 0)
		new_line.append(this->file_content.substr(0, found));
	new_line.append(target);
	if ((found + str.length()) < this->file_content.length())
		new_line.append(this->file_content.substr(found + str.length()));

	this->file_content = new_line;
	found = this->file_content.find(str);
	if (found == std::string::npos) return ;
	std::cout << this->file_content << std::endl;
	std::cout << found << std::endl;

	//this->replace(str, target);
}

bool	File::save(std::string file_path)
{
	std::ofstream output_file(file_path.c_str());

	if (!output_file.is_open()) return false;

	output_file << this->file_content;
	output_file.close();

	return true;
}

bool	File::loaded(void)
{
	return this->file_loaded;
}