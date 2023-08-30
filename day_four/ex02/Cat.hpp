/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:26:28 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 18:58:36 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal
{
private:
    Brain   *brain;

public:
    Cat( void );
    Cat( Cat const & Cat_to_copy);
    Cat& operator=( Cat const & Cat_to_copy);
    ~ Cat( void );

    void            makeSound( void ) const;
    std::string     get_idea(void) const;
    void            set_idea(std::string const new_idea) const;
    Brain           &get_brain(void) const;
    void            set_brain(Brain const &brain_to_copy);
};

#endif