/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:21 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:54:06 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{
public:
    Dog( void );
    Dog(Dog const &Dog_to_copy);
    Dog& operator=(Dog const &Dog_to_copy);
    ~Dog( void );

    void makeSound( void ) const;
};

#endif