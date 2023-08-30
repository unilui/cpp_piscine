/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:02:11 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:34:41 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form( void )
    :   name("noname"),
        target("uknown"),
        already_signed(false),
        grade_to_sign(1),
        grade_to_execute(1)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form
(
    std::string const name,
    std::string const target,
    int const grade_to_sign,
    int const grade_to_execute
)
    :   name(name),
        target(target),
        already_signed(false),
        grade_to_sign(grade_to_sign),
        grade_to_execute(grade_to_execute)
{
    this->validate_requirements();

    std::cout
        << name
        << " Form constructor called"
        << std::endl;
}

Form::Form(Form const &form_to_copy)
    :   name(form_to_copy.get_name()),
        grade_to_sign(form_to_copy.required_to_sign()),
        grade_to_execute(form_to_copy.required_to_execute())
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

std::string	Form::get_name( void ) const
{
    return (this->name);
}

std::string	Form::get_target( void ) const
{
    return (this->target);
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

const char* Form::UnsignedFormException::what() const throw()
{
	return ("Form is not signed!");
}

const char* Form::FileSystemException::what() const throw()
{
	return ("Can't create files :/");
}

Form::~Form( void )
{
    std::cout << "Form default destructor called" << std::endl;
}

bool    Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->already_signed)
    {
        std::cout
			<< bureaucrat.getName()
			<< " couldn't sign " 
			<< this->name
			<< " because the form is already signed."
			<< std::endl;
            
        throw Form::GradeTooLowException();
        return false;
    }
    if (bureaucrat.getGrade() > this->grade_to_sign)
	{
		std::cout
			<< bureaucrat.getName()
			<< " couldn't sign " 
			<< this->name
			<< " because the grade required to sign is too high!"
			<< std::endl;

        throw Form::GradeTooLowException();
        return false;
	}

    this->already_signed = true;
	std::cout
        << bureaucrat.getName()
        << " signed " 
        << this->name
        << std::endl;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os
    << "Name: " << form.get_name() << std::endl 
    << "Signed status: " << form.is_signed() << std::endl
    << "Required grade to sign: " << form.required_to_sign() << std::endl 
    << "Required grade to execute: " << form.required_to_execute() << std::endl;
	
	return os;
}