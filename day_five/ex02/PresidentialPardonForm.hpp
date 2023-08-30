/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 03:22:34 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:05:03 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm( void );
    PresidentialPardonForm(std::string const target);
    PresidentialPardonForm(PresidentialPardonForm const &form_to_copy);   
	PresidentialPardonForm &operator=(PresidentialPardonForm const &form_to_copy);
	~PresidentialPardonForm( void );

    void    execute(Bureaucrat const & executor) const;
};

#endif