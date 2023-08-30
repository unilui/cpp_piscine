/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:22:32 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:04:27 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) 
    : Form("PresidentialPardonForm", "uknown", 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) 
    : Form("PresidentialPardonForm", target, 25, 5)
{
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &form_to_copy)
    : Form(
        "PresidentialPardonForm",
        form_to_copy.get_target(),
        form_to_copy.required_to_sign(),
        required_to_execute())
{
	*this = form_to_copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &form_to_copy)
{
	if (this == &form_to_copy)
		return (*this);

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed())
    {
        throw PresidentialPardonForm::UnsignedFormException();
        return ;
    }
    if (executor.getGrade() > this->required_to_execute())
    {
        throw PresidentialPardonForm::GradeTooLowException();
        return ;
    }
    std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}