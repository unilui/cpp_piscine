/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:31:03 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 18:28:17 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>

class Brain
{
private:
	std::string ideas[100];
	int			last_idea;
	bool		new_idea;

	int	select_idea( void ) const;

public:
	Brain( void );
	Brain(Brain const &brain_to_copy);
	Brain &operator=(Brain const &brain_to_copy);
	~Brain( void );

	std::string get_idea( void );
	std::string get_idea(int idea) const;
	void        set_idea(std::string const new_idea);
	void        set_thoughts(std::string const player_one, std::string const player_two);
	int			get_last_idea_index( void ) const;
	bool		has_new_idea( void ) const;
};

#endif