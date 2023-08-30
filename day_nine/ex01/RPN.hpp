/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:35:33 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/26 17:32:00 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <stack>
#include <exception>
#include <iostream>

class RPN
{
private:
	static std::stack<int>	stk;

	static void	sum( void );
	static void	multiply( void );
	static void	divide( void );
	static void	subtract( void );

	static bool isNumber(char character);
	static bool	isValidExpression(std::string const expression);

	RPN( void );
	~RPN( void );
	RPN(RPN const &RPNToCopy);
	RPN &operator=(RPN const &RPNToCopy);

	class InvalidExpressionException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

public:
	static int	evaluate(std::string const expression);
};

#endif
