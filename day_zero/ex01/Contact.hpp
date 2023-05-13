/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:28:49 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/13 18:29:31 by lufelip2         ###   ########.fr       */
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
	bool		empty = true;

	std::string	truncate(std::string string);

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
