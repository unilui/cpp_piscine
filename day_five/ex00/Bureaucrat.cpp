/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:56:04 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/10 21:55:29 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:	name("Bureaucrat"),
		grade(__DEFAULT_GRADE__)
{
	std::cout
		<< "Bureaucrat default constructor called"
		<< std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int const grade)
	:	name(name),
		grade(__DEFAULT_GRADE__)
{
	if (this->validate_grade(grade))
		this->grade = grade;
	
	std::cout
		<< "Bureaucrat " << this->name
		<< " was constructed with grade " 
		<< this->grade << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat_to_copy)
{
	*this = bureaucrat_to_copy;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat_to_copy)
{
	if (this == &bureaucrat_to_copy)
		return (*this);

	this->grade = bureaucrat_to_copy.getGrade();

	return (*this);
}

int	Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

std::string	Bureaucrat::getName( void ) const
{
	return (this->name);
}

void	Bureaucrat::upGrade( void )
{
	if (this->validate_grade(this->grade - 1))
		this->grade--;
}

void	Bureaucrat::downGrade( void )
{
	if (this->validate_grade(this->grade + 1))
		this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade TOO HIGH!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade TOO LOW!");
}

bool	Bureaucrat::validate_grade(int new_grade) const
{
	if (new_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		return (false);
	}
	if (new_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		return (false);
	}
	return (true);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout
		<< "Bureaucrat default destructor called"
		<< std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os
		<< bureaucrat.getName() 
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< "." << std::endl;
	
	return os;
}
