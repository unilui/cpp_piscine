/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeValidations.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 05:38:41 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 10:03:08 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string BitcoinExchange::removeSpaces(std::string const &input)
{
    std::string result;

    for (size_t i = 0; i < input.length(); ++i)
    {
        if (input[i] != ' ')
            result += input[i];
    }
    return result;
}

bool    BitcoinExchange::hasOnlyDoubleSymbols(std::string const data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] < 48 || data[i] > 57)
        {
            if (data[i] == '+' && i > 0)
                return (false);
            if (data[i] == '-' && i > 0)
                return (false); 
            if (data[i] != '+' && data[i] != '-' && data[i] != '.')
                return (false);
        }
    }
    return (true);
}

bool BitcoinExchange::hasOnlyNumbers(std::string date)
{
    for (size_t i = 0; i < date.length(); i++)
    {
        if (date[i] < 48 || date[i] > 57)
                return (false);
    }
    return (true);
}

bool BitcoinExchange::isValidDate(std::string date)
{
    std::string str_year;
    std::string str_month;
    std::string str_day;
    int         year;
    int         month;
    int         day;

    if (date[4] != '-' || date[7] != '-')
        return (false);

    str_year = date.substr(0, 4);
    if (!hasOnlyNumbers(str_year))
        return (false);
    year = strToInt(str_year);
    if (year < 2009 || year > 2023)
        return (false);

    str_month = date.substr(5, 2);
    if (!hasOnlyNumbers(str_month))
        return (false);
    month = strToInt(str_month);
    if (month < 1 || month > 12)
        return (false);

    str_day = date.substr(8, 2);
    if (!hasOnlyNumbers(str_day))
        return (false);
    day = strToInt(str_day);
    if (day < 1 || day > 31)
        return (false);

    return (true);
}

bool BitcoinExchange::isValidExchangeRate(std::string exchange_rate)
{
    double rate;

    if (!hasOnlyDoubleSymbols(exchange_rate))
        return (false);
    
    rate = strToDouble(exchange_rate);
    
    if (rate < 0)
        return (false);

    return (true);        
}

bool BitcoinExchange::isValidValue(std::string new_value)
{
    double value;

    if (!hasOnlyDoubleSymbols(new_value))
    {
        std::cout << "Error: invalid number." << std::endl;
        return (false);
    }
    
    value = strToDouble(new_value);
    
    if (value < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return (false);
    }

    if (value > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return (false);
    }
    return (true);        
}

bool BitcoinExchange::isValidEntry(std::string new_entry)
{
    std::string date;
    std::string exchange_rate;
    size_t      delimiter;

    delimiter = new_entry.find(",");
    if (delimiter != 10 || delimiter == std::string::npos)
        return (false);

    date = new_entry.substr(0, 10);
    if (!isValidDate(date))
        return (false);

    if (new_entry.length() == 10)
        return (false);

    exchange_rate = new_entry.substr(11);
    if (!isValidExchangeRate(exchange_rate))
        return (false);      

    return (true);
}

bool BitcoinExchange::isValidConsult(std::string new_consult)
{
    std::string date;
    std::string value;
    std::string consult;
    size_t      delimiter;
    
    consult = removeSpaces(new_consult);
    delimiter = consult.find("|");
    if (delimiter != 10 || delimiter == std::string::npos)
    {
        std::cout << "Error: bad input => " << new_consult << std::endl;
        return (false);
    }

    date = consult.substr(0, 10);
    if (!isValidDate(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }

    if (consult.length() == 10)
    {
        std::cout << "Error: bad input => " << consult << std::endl;
        return (false);
    }

    value = consult.substr(11);
    if (!isValidValue(value))
        return (false);      

    return (true);
}