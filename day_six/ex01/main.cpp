/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:09:37 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 05:31:46 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
    Serializer serializer;
    Data        forty_two;
    uintptr_t   serialized_ptr;
    Data        *to_serialize;
    Data        *deserialized_ptr;

    forty_two.number = 42;
    
    to_serialize = &forty_two;
    serialized_ptr = serializer.serialize(to_serialize);
    deserialized_ptr = serializer.deserialize(serialized_ptr);
    
    std::cout << "Data: " << deserialized_ptr->number << std::endl;

    std::cout << "Original address: " << to_serialize << std::endl;
    std::cout << "Deserialized address: " << deserialized_ptr << std::endl;
    return (0);
}