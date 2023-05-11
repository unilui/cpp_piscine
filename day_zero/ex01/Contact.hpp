/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:28:49 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/10 19:13:15 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

class Contact {

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::string	truncate(std::string string);

public:
	Contact( void );
	~Contact( void );

	void		set_first_name(std::string new_first_name);
	void		set_last_name(std::string new_last_name);
	void		set_nickname(std::string new_nickname);
	void		set_phone_number(std::string new_phone_number);
	void		set_darkest_secret(std::string new_darkest_secret);

	std::string	summary(void);
	std::string	info(void);
};

#endif
