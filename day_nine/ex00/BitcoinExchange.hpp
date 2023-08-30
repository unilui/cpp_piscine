/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 04:17:38 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 10:21:55 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <string>       // std::string
#include <exception>    // std::exception
#include <iostream>     // std::cout, std::endl
#include <fstream>      // std::ifstream
#include <sstream>      // std::stringstream
#include <map>

class BitcoinExchange
{
private:
    static std::map<std::string, double> db;

    static void addEntry(std::string new_entry);
    static void consult(std::string new_consult);
    
    static std::string removeSpaces(std::string const &input);
    static bool isValidEntry(std::string new_entry);
    static bool isValidConsult(std::string new_consult);
    static bool isValidDate(std::string date);
    static bool isValidExchangeRate(std::string exchange_rate);
    static bool isValidValue(std::string value);
    static bool hasOnlyNumbers(std::string date);
    static bool hasOnlyDoubleSymbols(std::string const data);

    static int strToInt(std::string const data);
    static double strToDouble(std::string const data);

    BitcoinExchange( void );
    ~BitcoinExchange( void );
    BitcoinExchange(BitcoinExchange const &BitcoinExchangeToCopy);
	BitcoinExchange &operator=(BitcoinExchange const &BitcoinExchangeToCopy);

    class NoDataBaseException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
    class NoValidEntryException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
    class InvalidInputException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

public:
    static void loadDataBase(std::string file_name);
    static void pricesConsult(std::string file_name);
};

#endif