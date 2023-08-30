/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:26:28 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:53:58 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{
public:
    Cat( void );
    Cat( Cat const & Cat_to_copy);
    Cat& operator=( Cat const & Cat_to_copy);
    ~ Cat( void );

    void makeSound( void ) const;
};

#endif