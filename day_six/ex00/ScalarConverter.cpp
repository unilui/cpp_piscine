/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 05:40:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 19:40:09 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string ScalarConverter::numberToConvert    = "";
int         ScalarConverter::typeCode           = 0;

char        ScalarConverter::charType           = 0;
int         ScalarConverter::charTypeStatus     = 0;

int         ScalarConverter::intType            = 0;
int         ScalarConverter::intTypeStatus      = 0;

float       ScalarConverter::floatType          = 0;
double      ScalarConverter::doubleType         = 0;

ScalarConverter::ScalarConverter( void )
{
    std::cout << "Scalar converter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &ScalarConverterToCopy)
{
    (void)ScalarConverterToCopy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &ScalarConverterToCopy)
{
    (void)ScalarConverterToCopy;
    return *this;
}

ScalarConverter::~ScalarConverter( void )
{
    std::cout << "Scalar converter default destructor called" << std::endl;
}

const char* ScalarConverter::UnexpectedValueException::what() const throw()
{
	return ("Invalid input!\nExamples: 'c', '0', '-42', '0.0f', '-inff', 'nanf'");
}

bool    ScalarConverter::hasMaxDoubleSigns(std::string const data)
{
    size_t  positive_signs = 0;
    size_t  negative_signs = 0;
    size_t  e_sign = 0;

    for (size_t i = 0; i < data.length(); ++i)
    {
        if (data[i] == '+')
            positive_signs++;
        if (data[i] == '-')
            negative_signs++;
        if (data[i] == 'e')
            e_sign++;
        if ((positive_signs > 1 || negative_signs > 1) && i > 0)
        {
            if (data[i - 1] != 'e' && (data[i] == '+' || data[i] == '-'))
                return (false);
        }
    }
    if (e_sign > 1)
        return (false);

    return ((positive_signs + negative_signs) <= 2);
}

bool    ScalarConverter::hasOnlyOneSignAtFirstPosition(std::string const data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if ((data[i] == '+' || data[i] == '-') && i > 0)
            return (false);
    }
    return (true);
}

bool    ScalarConverter::hasOnlyOneFloatSign(std::string const data)
{
    bool float_sign = false;

    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] == 'f')
        {
            float_sign = true;
            if (i != (data.length() - 1))
                return (false);
        }
    }
    return (float_sign);
}

bool    ScalarConverter::hasOnlyOneDot(std::string const data)
{
    size_t dots = 0;

    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] == '.')
            dots++;
    }
    return (dots == 1);
}

bool    ScalarConverter::hasOnlyIntSymbols(std::string const data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] < 48 || data[i] > 57)
        {
            if (data[i] != '+' && data[i] != '-')
                return (false);
        }
    }
    return (true);
}

bool    ScalarConverter::hasOnlyFloatSymbols(std::string const data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] < 48 || data[i] > 57)
        {
            if (data[i] != '+'
                && data[i] != '-'
                && data[i] != '.'
                && data[i] != 'f')
                return (false);
        }
    }
    return (true);
}

bool    ScalarConverter::hasOnlyDoubleSymbols(std::string const data)
{
    for (size_t i = 0; i < data.length(); i++)
    {
        if (data[i] < 48 || data[i] > 57)
        {
            if (data[i] != '+'
                && data[i] != '-'
                && data[i] != '.'
                && data[i] != 'e')
                return (false);
        }
    }
    return (true);
}

bool	ScalarConverter::isCharType(std::string const data)
{
    if (data.length() > 1)
        return (false);
    if (data[0] >= 48 && data[0] <= 57)
        return (false);
    return (true);
}

bool	ScalarConverter::isIntType(std::string const data)
{
    if(!hasOnlyOneSignAtFirstPosition(data))
        return (false);
    if(!hasOnlyIntSymbols(data))
        return (false);
    return (true);
}

bool    ScalarConverter::isImaginaryFloat(std::string const data)
{
    if (!data.compare("-inff"))
        return (true);
    if (!data.compare("inff"))
        return (true);
    if (!data.compare("+inff"))
        return (true);
    if (!data.compare("nanf"))
        return (true);
    return (false);
}

bool	ScalarConverter::isFloatType(std::string const data)
{
    if (isImaginaryFloat(data))
        return (true);

    if (!hasOnlyFloatSymbols(data))
        return (false);
    if (!hasOnlyOneSignAtFirstPosition(data))
        return (false);
    if (!hasOnlyOneDot(data))
        return (false);
    if (!hasOnlyOneFloatSign(data))
        return (false);
    return (true);
}

bool    ScalarConverter::isImaginaryDouble(std::string const data)
{
    if (!data.compare("-inf"))
        return (true);
    if (!data.compare("inf"))
        return (true);
    if (!data.compare("+inf"))
        return (true);
    if (!data.compare("nan"))
        return (true);
    return (false);
}

bool	ScalarConverter::isDoubleType(std::string const data)
{
    if (isImaginaryDouble(data))
        return (true);

    if (!hasOnlyDoubleSymbols(data))
        return (false);
    if (!hasMaxDoubleSigns(data))
        return (false);
    if (!hasOnlyOneDot(data))
        return (false);
    return (true);
}

int     ScalarConverter::typeDetect(std::string const data)
{
    if (isCharType(data))
    {
        typeCode = SCALAR_TYPE_CHAR;
        std::cout << "Type detected: char" << std::endl;
        return SCALAR_TYPE_CHAR;
    }
    if (isIntType(data))
    {
        typeCode = SCALAR_TYPE_INT;
        std::cout << "Type detected: int" << std::endl;
        return SCALAR_TYPE_INT;
    }
    if (isFloatType(data))
    {
        typeCode = SCALAR_TYPE_FLOAT;
        std::cout << "Type detected: float" << std::endl;
        return SCALAR_TYPE_FLOAT;
    }
    if (isDoubleType(data))
    {
        typeCode = SCALAR_TYPE_DOUBLE;
        std::cout << "Type detected: double" << std::endl;
        return SCALAR_TYPE_DOUBLE;
    }
    return (UNEXPECTED_VALUE);
}

char    ScalarConverter::strToChar(std::string const data)
{
    char   character;

    std::stringstream iss(data);
    iss >> character;

    return (character);
}

int    ScalarConverter::strToInt(std::string const data)
{
    int number;

    std::stringstream iss(data);
    iss >> number;

    return (number);
}

float    ScalarConverter::strToFloat(std::string const data)
{
    float number;

    if (isImaginaryFloat(data))
    {
        if (!data.compare("inff"))
            number = std::numeric_limits<float>::infinity();
        if (!data.compare("+inff"))
            number = std::numeric_limits<float>::infinity();
        if (!data.compare("-inff"))
            number = -std::numeric_limits<float>::infinity();
        if (!data.compare("nanf"))
            number = std::numeric_limits<float>::quiet_NaN();

        charTypeStatus = IMPOSSIBLE_STATUS;
        intTypeStatus = IMPOSSIBLE_STATUS;
        return (number);
    }

    std::istringstream iss(data);
    iss >> number;

    return (number);
}

double  ScalarConverter::strToDouble(std::string const data)
{
    double number;

    if (isImaginaryDouble(data))
    {
        if (!data.compare("inf"))
            number = std::numeric_limits<double>::infinity();
        if (!data.compare("+inf"))
            number = std::numeric_limits<double>::infinity();
        if (!data.compare("-inf"))
            number = -std::numeric_limits<double>::infinity();
        if (!data.compare("nan"))
            number = std::numeric_limits<double>::quiet_NaN();

        charTypeStatus = IMPOSSIBLE_STATUS;
        intTypeStatus = IMPOSSIBLE_STATUS;
        return (number);
    }

    std::stringstream iss(data);
    iss >> number;

    return (number);
}

std::string ScalarConverter::charToStr(char scalar)
{
    std::string new_string;

    if (charTypeStatus == NON_DISPLAYABLE_STATUS)
        return ("Non displayable");
    if (charTypeStatus == OVERFLOW_STATUS)
        return ("Overflow");
    if (charTypeStatus == UNDERFLOW_STATUS)
        return ("Underflow");
    if (charTypeStatus == IMPOSSIBLE_STATUS)
        return ("Impossible");

    new_string = scalar;
    return (new_string);
}

std::string ScalarConverter::intToStr(int scalar)
{
    if (intTypeStatus == OVERFLOW_STATUS)
        return ("Overflow");
    if (intTypeStatus == UNDERFLOW_STATUS)
        return ("Underflow");
    if (intTypeStatus == IMPOSSIBLE_STATUS)
        return ("Impossible");

    std::stringstream ss;
    ss << scalar;

    return (ss.str());
}

std::string ScalarConverter::floatToStr(float scalar)
{
    std::stringstream ss;
    ss << std::setprecision(8) << scalar << "f";

    return (ss.str());
}

std::string ScalarConverter::doubleToStr(double scalar)
{
    std::stringstream ss;
    ss << std::setprecision(16) << scalar;

    return (ss.str());
}

void    ScalarConverter::convertToChar(void *scalar)
{
    switch (typeCode)
    {
        case SCALAR_TYPE_INT:
            charType = *(static_cast<int *>(scalar));
            break ;
        case SCALAR_TYPE_FLOAT:
            charType = *(static_cast<float *>(scalar));
            break ;
        case SCALAR_TYPE_DOUBLE:
            charType = *(static_cast<double *>(scalar));
            break ;
        default:
            break ;
    }

    if (charTypeStatus != 0)
        return ;

    charTypeStatus = DISPLAYABLE_STATUS;

    if (charType < 33 || charType > 126)
       charTypeStatus = NON_DISPLAYABLE_STATUS;

    if (strToInt(numberToConvert) > CHAR_MAX)
        charTypeStatus = OVERFLOW_STATUS;

    if (strToInt(numberToConvert) < CHAR_MIN)
        charTypeStatus = UNDERFLOW_STATUS;
}

void    ScalarConverter::convertToInt(void *scalar)
{
    switch (typeCode)
    {
        case SCALAR_TYPE_CHAR:
            intType = *(static_cast<char *>(scalar));
            break ;
        case SCALAR_TYPE_FLOAT:
            intType = *(static_cast<float *>(scalar));
            break ;
        case SCALAR_TYPE_DOUBLE:
            intType = *(static_cast<double *>(scalar));
            break ;
        default:
            break ;
    }

    if (intTypeStatus != 0)
        return ;

    intTypeStatus = DISPLAYABLE_STATUS;

    if (strToDouble(numberToConvert) > INT_MAX)
        intTypeStatus = OVERFLOW_STATUS;
    if (strToDouble(numberToConvert) < INT_MIN)
        intTypeStatus = UNDERFLOW_STATUS;
}

void    ScalarConverter::convertToFloat(void *scalar)
{
    switch (typeCode)
    {
        case SCALAR_TYPE_CHAR:
            floatType = *(static_cast<char *>(scalar));
            break ;
        case SCALAR_TYPE_INT:
            floatType = *(static_cast<int *>(scalar));
            break ;
        case SCALAR_TYPE_DOUBLE:
            floatType = *(static_cast<double *>(scalar));
            break ;
        default:
            break ;
    }
}

void    ScalarConverter::convertToDouble(void *scalar)
{
    switch (typeCode)
    {
        case SCALAR_TYPE_CHAR:
            doubleType = *(static_cast<char *>(scalar));
            break ;
        case SCALAR_TYPE_INT:
            doubleType = *(static_cast<int *>(scalar));
            break ;
        case SCALAR_TYPE_FLOAT:
            doubleType = *(static_cast<float *>(scalar));
            break ;
        default:
            break ;
    }
}

void	ScalarConverter::convert(std::string const data)
{
    void		*scalar[4];

    scalar[SCALAR_TYPE_CHAR]    = static_cast<void *>(&charType);
    scalar[SCALAR_TYPE_INT]     = static_cast<void *>(&intType);
    scalar[SCALAR_TYPE_FLOAT]   = static_cast<void *>(&floatType);
    scalar[SCALAR_TYPE_DOUBLE]  = static_cast<void *>(&doubleType);

    numberToConvert = data;

    switch (typeDetect(data))
    {
        case SCALAR_TYPE_CHAR:
            charType = strToChar(data);
            break ;
        case SCALAR_TYPE_INT:
            intType = strToInt(data);
            break ;
        case SCALAR_TYPE_FLOAT:
            floatType = strToFloat(data);
            break ;
        case SCALAR_TYPE_DOUBLE:
            doubleType = strToDouble(data);
            break ;
        default:
            throw ScalarConverter::UnexpectedValueException();
            return ;
    }

    convertToChar(scalar[typeCode]);
    convertToInt(scalar[typeCode]);
    convertToFloat(scalar[typeCode]);
    convertToDouble(scalar[typeCode]);

    std::cout << "char: " << charToStr(charType) << std::endl;
    std::cout << "int: " << intToStr(intType) << std::endl;
    std::cout << "float: " << floatToStr(floatType) << std::endl;
    std::cout << "double: " << doubleToStr(doubleType) << std::endl;
}
