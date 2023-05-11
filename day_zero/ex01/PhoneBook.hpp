/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:21:05 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/10 20:33:29 by lufelip2         ###   ########.fr       */
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

	void	show_contacts( void );

public:
	PhoneBook( void );
	~PhoneBook( void );

	void	search( void );

};

#endif
