/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:02:45 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 08:03:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
 #define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const   name;
	std::string const	target;
	bool                already_signed;
	int const           grade_to_sign;
	int const           grade_to_execute;

	void    validate_requirements( void ) const;

public:
	Form( void );
	Form(std::string const name, std::string const target, int const grade_to_sign,int const grade_to_execute);
	Form(Form const &form_to_copy);   
	Form &operator=(Form const &form_to_copy);
	virtual ~Form( void );

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
	class UnsignedFormException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class FileSystemException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	bool    			is_signed( void ) const;
	int     			required_to_sign( void ) const;
	int     			required_to_execute(void) const;
	std::string			get_name( void ) const;
	std::string			get_target( void ) const;

	bool				beSigned(Bureaucrat const &bureaucrat);
	virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif