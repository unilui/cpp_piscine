/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:48:27 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:55:39 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string type;

public:
    WrongAnimal( void );
    WrongAnimal(std::string const type);
    WrongAnimal(WrongAnimal const &WrongAnimal_to_copy);
    WrongAnimal& operator=(WrongAnimal const &WrongAnimal_to_copy);
    virtual ~WrongAnimal( void );

    std::string getType( void ) const;
    void makeSound( void ) const;
};

#endif