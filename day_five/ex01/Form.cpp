/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:58:44 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/10 23:14:48 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void )
    :   name("noname"),
        already_signed(false),
        grade_to_execute(1),
        grade_to_sign(1)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form
(
    std::string const name,
    int const grade_to_sign,
    int const grade_to_execute
)
    :   name(name),
        already_signed(false),
        grade_to_execute(grade_to_execute),
        grade_to_sign(grade_to_sign)
{
    this->validate_requirements();

    std::cout
        << name
        << " Form constructor called"
        << std::endl;
}

Form::Form(Form const &form_to_copy)
{
	*this = form_to_copy;
}

Form &Form::operator=(Form const &form_to_copy)
{
	if (this == &form_to_copy)
		return (*this);

    this->already_signed = form_to_copy.is_signed();

	return (*this);
}

bool    Form::is_signed( void ) const
{
    return (this->already_signed);
}

int     Form::required_to_sign( void ) const
{
    return (this->grade_to_sign);
}

int     Form::required_to_execute( void ) const
{
    return (this->grade_to_execute);
}

void    Form::validate_requirements( void ) const
{
    if (this->grade_to_sign < 1 || grade_to_execute < 1)
    {
        throw Form::GradeTooHighException();
        return ;
    }
    if (this->grade_to_execute > 150 || grade_to_sign > 150)
    {
        throw Form::GradeTooLowException();
        return ;
    }
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form requirements TOO HIGH!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form requirements TOO LOW!");
}

Form::~Form( void )
{
    std::cout << "Form default destructor called" << std::endl;
}
