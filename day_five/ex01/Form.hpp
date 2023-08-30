/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:58:38 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:28:37 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
 #define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	std::string const   name;
	bool                already_signed;
	int const           grade_to_sign;
	int const           grade_to_execute;

	void    validate_requirements( void ) const;

public:
	Form( void );
	Form(std::string const name, int const grade_to_sign,int const grade_to_execute);
	Form(Form const &form_to_copy);   
	Form &operator=(Form const &form_to_copy);
	~Form( void );

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

	bool    	is_signed( void ) const;
	int     	required_to_sign( void ) const;
	int     	required_to_execute(void) const;
	std::string	get_name( void ) const;

	bool		beSigned(Bureaucrat const &bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif