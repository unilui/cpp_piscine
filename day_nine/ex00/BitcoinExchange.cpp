/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 04:17:36 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 16:39:29 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, double> BitcoinExchange::db = std::map<std::string, double>();

BitcoinExchange::BitcoinExchange( void ) { return ; }

BitcoinExchange::~BitcoinExchange( void ) { return ; }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &BitcoinExchangeToCopy)
{
    static_cast<void>(BitcoinExchangeToCopy);
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &BitcoinExchangeToCopy)
{
    static_cast<void>(BitcoinExchangeToCopy);
    return *this;
}
