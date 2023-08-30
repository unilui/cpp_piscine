/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:11 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 19:09:59 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	this->brain = new Brain();
	this->brain->set_thoughts("Cat", "Dog");

	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const &cat_to_copy) : Animal(cat_to_copy.getType())
{
	*this = cat_to_copy;
}

Cat	&Cat::operator=(Cat const &Cat_to_copy)
{
	if (this == &Cat_to_copy)
		return (*this);

	Brain *new_brain = new Brain();

	*new_brain = Cat_to_copy.get_brain();
	delete this->brain;

	this->brain = new_brain;
	
	return (*this);
}

Cat::~Cat( void )
{
	delete this->brain;

	std::cout << "Cat default destructor called" << std::endl;
}

void  Cat::makeSound( void ) const
{
	std::cout << "Miau Miau MIAAAUUUUU!!" << std::endl;
}

std::string	Cat::get_idea(void) const
{
	return (this->brain->get_idea());
}

void	Cat::set_idea(std::string const new_idea) const
{
	this->brain->set_idea(new_idea);
}

Brain	&Cat::get_brain(void) const
{
	return (*this->brain);
}

void    Cat::set_brain(Brain const &brain_to_copy)
{
	delete this->brain;

	Brain *new_brain = new Brain();

	*new_brain = brain_to_copy;

	this->brain = new_brain;
}