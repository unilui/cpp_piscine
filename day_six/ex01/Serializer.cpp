/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:09:40 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 05:21:14 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer( void )
{
    std::cout << "Serializer default constructor called" << std::endl;
}
	
Serializer::Serializer(Serializer const &SerializerToCopy)
{
    (void)SerializerToCopy;
}
    
Serializer &Serializer::operator=(Serializer const &SerializerToCopy)
{
    (void)SerializerToCopy;
    return *this;
}

Serializer::~Serializer( void )
{
    std::cout << "Serializer default destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}