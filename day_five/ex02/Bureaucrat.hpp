/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:56:01 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:36:21 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>

#define __DEFAULT_GRADE__ 150

class Form;

class Bureaucrat
{
private:
	std::string const	name;
	int					grade;
	
	bool				validate_grade(int new_grade) const;

public:
	Bureaucrat( void );
	Bureaucrat(std::string const name, int const grade);
	Bureaucrat(Bureaucrat const &bureaucrat_to_copy);
	Bureaucrat &operator=(Bureaucrat const &bureaucrat_to_copy);
	~Bureaucrat( void );

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	int			getGrade( void ) const;
	std::string	getName( void ) const;
	
	void		upGrade( void );
	void		downGrade( void );
	bool		signForm(Form &form) const;
	void		executeForm(Form const & form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
