/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:28:49 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/15 20:56:57 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cctype>

class Contact {

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	bool		empty;

	bool		is_alpha(std::string str);
	bool		is_numeric(std::string str);
	bool		is_alpha_numeric(std::string str);
	std::string	truncate(std::string str);

public:
	Contact( void );
	~Contact( void );

	void		set_first_name( void );
	void		set_last_name( void );
	void		set_nickname( void );
	void		set_phone_number( void );
	void		set_darkest_secret( void );
	bool		is_empty(void);
	void		save(void);

	std::string	summary(void);
	std::string	info(void);
};

#endif
