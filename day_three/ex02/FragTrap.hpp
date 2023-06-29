/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:50:44 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 19:08:26 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap 
{

public:
	FragTrap( void );
    FragTrap(const std::string name);
	FragTrap(FragTrap const &FragTrap_to_copy);
	FragTrap& operator=(FragTrap const &FragTrap_to_copy);
	~FragTrap(void);

	void	attack(const std::string& target);
	void	high_fives_guys(void);
};

#endif