/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:19 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 19:11:43 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	this->brain = new Brain();
	this->brain->set_thoughts("Dog", "Cat");

	std::cout << "Dog default constructor called" << std::endl; 
}

Dog::Dog(Dog const &dog_to_copy) : Animal(dog_to_copy.getType())
{
	*this = dog_to_copy;
}

Dog& Dog::operator=(Dog const &Dog_to_copy)
{
	if (this == &Dog_to_copy)
		return (*this);

	Brain *new_brain = new Brain();

	*new_brain = Dog_to_copy.get_brain();
	delete this->brain;

	this->brain = new_brain;
	
	return (*this);
}

Dog::~Dog( void )
{
	delete this->brain;

	std::cout << "Dog default destructor called" << std::endl;
}

void Dog::makeSound( void ) const
{
	std::cout << "A A AUUUUUUUUUUUUUUUUUUUUUUUUUUU" << std::endl;
}

std::string	Dog::get_idea(void) const
{
	return (this->brain->get_idea());
}

void	Dog::set_idea(std::string const new_idea) const
{
	this->brain->set_idea(new_idea);
}

Brain	&Dog::get_brain(void) const
{
	return (*this->brain);
}

void    Dog::set_brain(Brain const &brain_to_copy)
{
	delete this->brain;

	Brain *new_brain = new Brain();

	*new_brain = brain_to_copy;

	this->brain = new_brain;
}