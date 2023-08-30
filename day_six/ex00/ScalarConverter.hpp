/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 05:37:13 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 19:38:40 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>
#include <sstream>
#include <iomanip>
#include <climits>
#include <limits>
#include <cmath>

#define UNEXPECTED_VALUE 4
#define SCALAR_TYPE_CHAR 0
#define SCALAR_TYPE_INT	1
#define	SCALAR_TYPE_FLOAT 2
#define SCALAR_TYPE_DOUBLE 3

#define DISPLAYABLE_STATUS 1
#define NON_DISPLAYABLE_STATUS 2
#define OVERFLOW_STATUS 3
#define UNDERFLOW_STATUS 4
#define IMPOSSIBLE_STATUS 5

class ScalarConverter
{
private:
	static std::string numberToConvert;
	static int		typeCode;

	static char		charType;
	static int		charTypeStatus;

	static int		intType;
	static int		intTypeStatus;

	static float	floatType;
	static double	doubleType;

	static int	typeDetect(std::string const data);
	static bool	isCharType(std::string const data);
	static bool	isIntType(std::string const data);
	static bool	isFloatType(std::string const data);
	static bool	isDoubleType(std::string const data);

	static bool isImaginaryFloat(std::string const data);
	static bool isImaginaryDouble(std::string const data);
	static bool	hasOnlyFloatSymbols(std::string const data);
	static bool	hasOnlyIntSymbols(std::string const data);
	static bool	hasOnlyDoubleSymbols(std::string const data);
	static bool hasMaxDoubleSigns(std::string const data);
	static bool hasOnlyOneSignAtFirstPosition(std::string const data);
	static bool hasOnlyOneFloatSign(std::string const data);
	static bool	hasOnlyOneSign(std::string const data);
	static bool hasOnlyOneDot(std::string const data);

	static char	strToChar(std::string const data);
	static int	strToInt(std::string const data);
	static float strToFloat(std::string const data);
	static double strToDouble(std::string const data);

	static std::string charToStr(char scalar);
	static std::string intToStr(int scalar);
	static std::string floatToStr(float scalar);
	static std::string doubleToStr(double scalar);

	static void	convertToChar(void *scalar);
	static void	convertToInt(void *scalar);
	static void	convertToFloat(void *scalar);
	static void	convertToDouble(void *scalar);

	ScalarConverter( void );
	ScalarConverter(ScalarConverter const &ScalarConverterToCopy);
	ScalarConverter &operator=(ScalarConverter const &ScalarConverterToCopy);
	~ScalarConverter( void );

public:

	class UnexpectedValueException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	static void	convert(std::string const string);
};

#endif
