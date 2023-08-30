/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:04:58 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:05:16 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm( void );
    RobotomyRequestForm(std::string const target);
    RobotomyRequestForm(RobotomyRequestForm const &form_to_copy);   
	RobotomyRequestForm &operator=(RobotomyRequestForm const &form_to_copy);
	~RobotomyRequestForm( void );

    void    execute(Bureaucrat const & executor) const;
};

#endif