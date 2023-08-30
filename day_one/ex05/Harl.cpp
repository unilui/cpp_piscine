/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:02:27 by lufelip2          #+#    #+#             */
/*   Updated: 2023/05/25 01:41:30 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->levels[0] = &Harl::debug;
	this->level_lables[0] = "DEBUG";
	this->levels[1] = &Harl::info;
	this->level_lables[1] = "INFO";
	this->levels[2] = &Harl::warning;
	this->level_lables[2] = "WARNING";
	this->levels[3] = &Harl::error;
	this->level_lables[3] = "ERROR";
}

Harl::~Harl(void) { return ; }

void	Harl::complain(std::string level)
{
	int	level_qty;

	level_qty = sizeof(this->level_lables) / sizeof(std::string);

	for (int level_id = 0; level_id < level_qty; level_id++)
	{
		if (!level.compare(this->level_lables[level_id]))
		{
			(this->*levels[level_id])();
			return ;
		}
	}
	this->default_complain();
}

void Harl::debug(void)
{
	std::cout << _DEBUG_COMPLAIN_ << std::endl;
}

void Harl::info(void)
{
	std::cout << _INFO_COMPLAIN_ << std::endl;
}

void Harl::warning(void)
{
	std::cout << _WARNING_COMPLAIN_ << std::endl;
}

void Harl::error(void)
{
	std::cout << _ERROR_COMPLAIN_ << std::endl;
}

void Harl::default_complain(void)
{
	std::cout << _DEFAULT_COMPLAIN << std::endl;
}
