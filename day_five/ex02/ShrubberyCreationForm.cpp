/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:36:01 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 07:01:31 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) 
    : Form("ShrubberyCreationForm", "uknown", 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) 
    : Form("ShrubberyCreationForm", target, 145, 137)
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &form_to_copy)
    : Form(
        "ShrubberyCreationForm",
        form_to_copy.get_target(),
        form_to_copy.required_to_sign(),
        required_to_execute())
{
	*this = form_to_copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &form_to_copy)
{
	if (this == &form_to_copy)
		return (*this);

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->is_signed())
    {
        throw ShrubberyCreationForm::UnsignedFormException();
        return ;
    }
    if (executor.getGrade() > this->required_to_execute())
    {
        throw ShrubberyCreationForm::GradeTooLowException();
        return ;
    }

    std::string file_name = this->get_target() + "_shrubbery";
    std::ofstream file(file_name.c_str());
    
    if (!file.is_open())
    {
        throw ShrubberyCreationForm::FileSystemException();
        return;
    }
    
    file 
        << "       /\\"
        << "\n      //\\\\"
        << "\n     ///\\\\\\"
        << "\n    ////\\\\\\\\"
        << "\n   /////\\\\\\\\\\"
        << "\n  //////\\\\\\\\\\\\"
        << "\n ///////\\\\\\\\\\\\\\";
    
    file.close();
}