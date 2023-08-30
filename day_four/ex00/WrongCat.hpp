/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:53:24 by lufelip2          #+#    #+#             */
/*   Updated: 2023/06/29 21:54:31 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{
public:
    WrongCat( void );
    WrongCat( WrongCat const & WrongCat_to_copy);
    WrongCat& operator=( WrongCat const & WrongCat_to_copy);
    ~ WrongCat( void );

    void makeSound( void ) const;
};

#endif