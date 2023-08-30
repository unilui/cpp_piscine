/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeCasters.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 06:48:01 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 07:30:33 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int    BitcoinExchange::strToInt(std::string const data)
{
    int number;

    std::stringstream iss(data);
    iss >> number;

    return (number);
}

double  BitcoinExchange::strToDouble(std::string const data)
{
    double number;

    std::stringstream iss(data);
    iss >> number;

    return (number);
}