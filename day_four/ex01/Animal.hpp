/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:09 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 19:08:26 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
    std::string type;

public:
    Animal( void );
    Animal(std::string const type);
    Animal(Animal const &animal_to_copy);
    Animal& operator=(Animal const &animal_to_copy);
    virtual ~Animal( void );

    std::string getType( void ) const;
    virtual void makeSound( void ) const;
    virtual std::string     get_idea(void) const = 0;
    virtual void            set_idea(std::string const new_idea) const = 0;
    virtual Brain&          get_brain(void) const = 0;
    virtual void            set_brain(Brain const &brain_to_copy) = 0;
};

#endif