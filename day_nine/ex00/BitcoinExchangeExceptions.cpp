/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeExceptions.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 05:43:57 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 09:40:12 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char* BitcoinExchange::NoDataBaseException::what() const throw()
{        
	return
    (
        "No database file was found in the current directory!\n"
        "The file should be named as \"data.csv\"."
    );
}

const char* BitcoinExchange::NoValidEntryException::what() const throw()
{        
	return
    (
        "No valid entry was found in the database file!"
    );
}

const char* BitcoinExchange::InvalidInputException::what() const throw()
{        
	return
    (
        "Can't open list of consults!"
    );
}