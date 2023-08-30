/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:36:05 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:58:27 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cctype>

class ShrubberyCreationForm : public Form
{
public:
    ShrubberyCreationForm( void );
    ShrubberyCreationForm(std::string const target);
    ShrubberyCreationForm(ShrubberyCreationForm const &form_to_copy);   
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &form_to_copy);
	~ShrubberyCreationForm( void );

    void    execute(Bureaucrat const & executor) const;
};

#endif