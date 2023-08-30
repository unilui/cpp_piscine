/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:21:05 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/15 20:38:38 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>
# include <cstdlib>

#include "Contact.hpp"

#define _PHONE_ADD_		0
#define _PHONE_SEARCH_	1
#define _PHONE_EXIT_	2
#define _PHONE_INVALID_	3

class PhoneBook {

private:
	Contact	contacts[8];
	int		actual_index;

	void	show_contacts( void );
	int		get_contact_index( void );
	void	show_menu( void );
	int		atoi(std::string str);

public:
	PhoneBook( void );
	~PhoneBook( void );

	void	search( void );
	void	add( void );
	int		get_option( void );
	bool	invalid_input(void);
	void	whisper(std::string message);
};

#endif
