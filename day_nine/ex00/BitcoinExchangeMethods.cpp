/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeMethods.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 05:48:18 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 10:24:38 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    BitcoinExchange::loadDataBase(std::string file_name)
{
    std::ifstream   dataBase(file_name.c_str());
    std::string     new_entry;

    if (!dataBase.is_open())
    {
        throw BitcoinExchange::NoDataBaseException();
        return ;
    }

    while (std::getline(dataBase, new_entry))
    {
        if (isValidEntry(new_entry))
            addEntry(new_entry);
    }

    dataBase.close();

    if (db.size() == 0)
        throw BitcoinExchange::NoValidEntryException();
}

void    BitcoinExchange::addEntry(std::string new_entry)
{
    std::string date;
    double  exchange_rate;

    date = new_entry.substr(0, 10);
    exchange_rate = strToDouble(new_entry.substr(11));
    db.insert(std::make_pair(date, exchange_rate));
}

void    BitcoinExchange::pricesConsult(std::string file_name)
{
    std::ifstream   consultList(file_name.c_str());
    std::string     new_consult;

    if (!consultList.is_open())
    {
        throw BitcoinExchange::InvalidInputException();
        return ;
    }

    while (std::getline(consultList, new_consult))
    {
        if (isValidConsult(new_consult))
            consult(new_consult);
    }

    consultList.close();
}

void    BitcoinExchange::consult(std::string new_consult)
{
    std::string date;
    double      value;
        
    new_consult = removeSpaces(new_consult);
    date = new_consult.substr(0, 10);
    value = strToDouble(new_consult.substr(11));

    std::cout << date << " => " << value << " = ";

    std::map<std::string, double>::iterator it;
    it = db.find(date);
    if (it != db.end())
    {
        std::cout << (it->second * value) << std::endl;
    } 
    else
    {   
        addEntry(new_consult);
        it = db.find(date);
        if (it != db.begin())
            --it;
        db.erase(date);
        std::cout << (it->second * value);
        std::cout 
            << " (Aproximated value in: " 
            << it->first 
            << ")" << std::endl;
    }
}