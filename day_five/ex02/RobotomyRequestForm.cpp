/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 02:05:31 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/18 06:05:22 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) 
    : Form("RobotomyRequestForm", "uknown", 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) 
    : Form("RobotomyRequestForm", target, 72, 45)
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &form_to_copy)
    : Form(
        "RobotomyRequestForm",
        form_to_copy.get_target(),
        form_to_copy.required_to_sign(),
        required_to_execute())
{
	*this = form_to_copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &form_to_copy)
{
	if (this == &form_to_copy)
		return (*this);

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static bool half_time = false;
    if (!this->is_signed())
    {
        throw RobotomyRequestForm::UnsignedFormException();
        return ;
    }
    if (executor.getGrade() > this->required_to_execute())
    {
        throw RobotomyRequestForm::GradeTooLowException();
        return ;
    }
    std::cout << "Making some drilling noises" << std::endl;
    std::cout << executor.getName() << " executed " << this->get_name() << std::endl;
    
    if (half_time)
        std::cout << this->get_target() << " was robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << this->get_target() << " failed!" << std::endl;
    half_time = !half_time;
}
