/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:21:05 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/13 17:03:40 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <string>

#include "Contact.hpp"

class PhoneBook {

private:
	Contact	contacts[8];
	int		actual_index = 0;

	void	show_contacts( void );
	int		get_contact_index( void );

public:
	PhoneBook( void );
	~PhoneBook( void );

	void	search( void );
	void	add( void );
};

#endif
