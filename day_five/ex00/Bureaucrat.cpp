/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:56:04 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/04 18:42:49 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
	:	name("noname"),
		grade(150)
{ return ; }

Bureaucrat::Bureaucrat(std::string const name, int const grade)
	:	name(name),
		grade(grade)
{ return ; }

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
	this->grade--;
}

void	Bureaucrat::downGrade( void )
{
	this->grade++;
}

Bureaucrat::~Bureaucrat( void ) { return ; }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << " bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
