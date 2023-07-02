/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:09 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:22:26 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

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
};

#endif