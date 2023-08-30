/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:55:29 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 07:50:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cctype>

class Intern
{
private:
    Form   *new_presidential_pardon_form(std::string target);
    Form   *new_robotomy_request_form(std::string target);
    Form   *new_shrubbery_creation_form(std::string targer);

    Form	*(Intern::*forms[3])(std::string target);
	std::string	form_lables[3];

public:
    Intern( void );
    Intern(Intern const &intern_to_copy);
	Intern &operator=(Intern const &intern_to_copy);
    ~Intern( void );

    Form   *makeForm(std::string name, std::string target);
};

#endif