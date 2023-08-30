/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:55:31 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 08:00:58 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	this->forms[0] = &Intern::new_presidential_pardon_form;
	this->form_lables[0] = "presidentialpardonform";
	this->forms[1] = &Intern::new_robotomy_request_form;
	this->form_lables[1] = "robotomyrequestform";
	this->forms[2] = &Intern::new_shrubbery_creation_form;
	this->form_lables[2] = "shrubberycreationform";

    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &intern_to_copy)
{
    *this = intern_to_copy;
}

Intern &Intern::operator=(Intern const &intern_to_copy)
{
	if (this == &intern_to_copy)
		return (*this);

	return (*this);
}

void removeSpaces(std::string& str)
{
    std::string result;
    for (std::size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ')
            result += str[i];
    }
    str = result;
}

void toLowerCase(std::string& str)
{
    for (size_t i = 0; i < str.size(); ++i)
        str[i] = std::tolower(str[i]);
}

Form   *Intern::new_presidential_pardon_form(std::string target)
{
    std::cout << "Intern creates presidential pardon form." << std::endl;
    return new PresidentialPardonForm(target);
}

Form   *Intern::new_robotomy_request_form(std::string target)
{
    std::cout << "Intern creates robotomy request form." << std::endl;
    return new RobotomyRequestForm(target);
}

Form   *Intern::new_shrubbery_creation_form(std::string target)
{
    std::cout << "Intern creates shrubbery creation form." << std::endl;
    return new ShrubberyCreationForm(target);
}

Form   *Intern::makeForm(std::string name, std::string target)
{
    int	form_qty = sizeof(this->form_lables) / sizeof(std::string); 

    removeSpaces(name);
    toLowerCase(name);

	for (int form_id = 0; form_id < form_qty; form_id++)
	{       
		if ((this->form_lables[form_id]).find(name) != std::string::npos)
			return (this->*forms[form_id])(target);
	}
	std::cout << "I'm not payed for this! This form doesn't exists." << std::endl;
    return NULL;
}

Intern::~Intern( void )
{
    std::cout << "Intern default destructor called." << std::endl;
}