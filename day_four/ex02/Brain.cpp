/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 22:49:23 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 19:09:01 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string IntToString(int number)
{
    std::ostringstream oss;
    oss << number;
    return oss.str();
}


Brain::Brain( void ) : new_idea(false)
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &brain_to_copy)
{
    *this = brain_to_copy;    
}

Brain &Brain::operator=(Brain const &brain_to_copy)
{
    for (int idea = 0; idea < 100; idea++)
        this->ideas[idea] = brain_to_copy.get_idea(idea);

    this->new_idea = brain_to_copy.has_new_idea();
    this->last_idea = brain_to_copy.get_last_idea_index();

    return (*this);
}

int Brain::select_idea(void) const
{
    std::srand(std::time(0));
    return (std::rand() % 100);
}

std::string    Brain::get_idea(int idea) const
{
    return (this->ideas[idea]);
}

std::string    Brain::get_idea( void )
{
    if (this->new_idea)
    {
        this->new_idea = false;
        return (this->ideas[this->last_idea]);
    }
    return (this->ideas[this->select_idea()]);
}

void    Brain::set_idea(std::string const new_idea)
{
    this->new_idea = true;
    this->last_idea = this->select_idea();
    this->ideas[last_idea] = new_idea;
}

void    Brain::set_thoughts(std::string const player_one, std::string const player_two)
{
    for (int idea = 0; idea < 100; idea++)
    {
        this->ideas[idea] = player_one + " is " + IntToString(idea);
        this->ideas[idea] += " times better than " + player_two;
    }
}

int		Brain::get_last_idea_index( void ) const
{
    return (this->last_idea);
}

bool    Brain::has_new_idea( void ) const
{
    return (this->new_idea);
}

Brain::~Brain( void )
{
    std::cout << "Brain default destructor called" << std::endl;
}