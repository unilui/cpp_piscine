/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 18:58:46 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
private:
    Brain   *brain;

public:
    Dog( void );
    Dog(Dog const &Dog_to_copy);
    Dog& operator=(Dog const &Dog_to_copy);
    ~Dog( void );

    void            makeSound( void ) const;
    std::string     get_idea(void) const;
    void            set_idea(std::string const new_idea) const;
     Brain          &get_brain(void) const;
    void            set_brain(Brain const &brain_to_copy);
};

#endif