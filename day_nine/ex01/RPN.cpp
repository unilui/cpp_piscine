/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:35:36 by lufelip2          #+#    #+#             */
/*   Updated: 2023/08/02 15:27:24 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int> RPN::stk = std::stack<int>();

RPN::RPN( void ) { return ; }

RPN::~RPN( void ) { return ; }

RPN::RPN(RPN const &RPNToCopy)
{
	static_cast<void>(RPNToCopy);
}

RPN &RPN::operator=(RPN const &RPNToCopy)
{
	static_cast<void>(RPNToCopy);
	return *this;
}

bool RPN::isValidExpression(std::string const expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		if (expression[i] < 48 || expression[i] > 57)
		{
			if (expression[i] != '+'
				&& expression[i] != '-'
				&& expression[i] != '*'
				&& expression[i] != '/'
				&& expression[i] != ' ')
				return (false);
		}
		if (i % 2 == 0 && expression[i] == ' ')
			return (false);
		if (i % 2 == 1 && expression[i] != ' ')
			return (false);
	}
	return (true);
}

void	RPN::sum(void)
{
	int	first;
	int	second;

	if (stk.size() < 2)
		throw RPN::InvalidExpressionException();

	second = stk.top();
	stk.pop();
	first = stk.top();
	stk.pop();
	stk.push(first + second);
}

void	RPN::multiply(void)
{
	int	first;
	int	second;

	if (stk.size() < 2)
		throw RPN::InvalidExpressionException();

	second = stk.top();
	stk.pop();
	first = stk.top();
	stk.pop();
	stk.push(first * second);
}

void	RPN::divide(void)
{
	int	first;
	int	second;

	if (stk.size() < 2)
		throw RPN::InvalidExpressionException();

	second = stk.top();
	stk.pop();
	first = stk.top();
	stk.pop();
	stk.push(first / second);
}

void	RPN::subtract(void)
{
	int	first;
	int	second;

	if (stk.size() < 2)
		throw RPN::InvalidExpressionException();

	second = stk.top();
	stk.pop();
	first = stk.top();
	stk.pop();
	stk.push(first - second);
}

bool	RPN::isNumber(char character)
{
	return(character >= 48 && character <= 57);
}

int	RPN::evaluate(std::string const expression)
{
	if (!isValidExpression(expression))
		throw RPN::InvalidExpressionException();

	for (size_t i = 0; i < expression.length(); i++)
	{
		if (isNumber(expression[i]))
			stk.push(expression[i] - '0');
		else if (expression[i] == '+')
			sum();
		else if (expression[i] == '-')
			subtract();
		else if (expression[i] == '/')
			divide();
		else if (expression[i] == '*')
			multiply();
		else
			continue ;
	}

	if (stk.size() > 1)
		throw RPN::InvalidExpressionException();

	return (stk.top());
}

const char* RPN::InvalidExpressionException::what() const throw()
{
	return
	(
		"Invalid expression!\n"
		"Example: \"1 2 * 2 / 2 * 2 4 - +\"."
	);
}
