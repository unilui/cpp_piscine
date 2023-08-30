/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:02:24 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/25 01:39:16 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#define _DEBUG_COMPLAIN_ "I love having extra bacon for my 7XL-double-cheese-\
triple-pickle-special-ketchup burger. I really do!"

#define _INFO_COMPLAIN_ "I cannot believe adding extra bacon costs more money\
. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking \
for more!"

#define _WARNING_COMPLAIN_ "I think I deserve to have some extra bacon for fre\
e. I’ve been coming for years whereas you started working here since last month."

#define _ERROR_COMPLAIN_ "This is unacceptable! I want to speak to the manager now."

#define _DEFAULT_COMPLAIN "I have rights and I will use them!!"

#include <string>
#include <iostream>

class Harl
{

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	void	default_complain(void);

	void	(Harl::*levels[4])();
	std::string	level_lables[4];

public:
	Harl(void);
	~Harl(void);

	void complain(std::string level);
};

#endif
