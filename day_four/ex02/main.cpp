/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:15:24 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 19:19:39 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
    //Animal  stupid;
    Animal* stupid_array[4];
    
    std::cout << "\nCreating first auau!\n" << std::endl;
    stupid_array[0] = new Dog();

    std::cout << "\nCreating second auau!\n" << std::endl;
    stupid_array[1] = new Dog();

    std::cout << "\nCreating first miau miau!\n" << std::endl;
    stupid_array[2] = new Cat();

    std::cout << "\nCreating second miau miau!\n" << std::endl;
    stupid_array[3] = new Cat();

    std::cout << "\nSilence, first miau miau thinking!\n" << std::endl;
    std::cout << "miau miau says: " << std::endl;
    stupid_array[2]->makeSound();
    std::cout << stupid_array[2]->get_idea() << std::endl;

    stupid_array[2]->set_idea("Cats don't like cpp!");

    (*stupid_array[3]) = (*stupid_array[2]);
    
    std::cout << stupid_array[3]->get_idea() << std::endl;

    std::cout << "\nSilence, first auau thinking!\n" << std::endl;
    std::cout << "auau says: " << std::endl;
    stupid_array[0]->makeSound();
    std::cout << stupid_array[0]->get_idea() << std::endl;

    stupid_array[0]->set_idea("Dogs don't like cpp!");

    (*stupid_array[1]) = (*stupid_array[0]);
    
    std::cout << stupid_array[1]->get_idea() << std::endl;

    std::cout << "\nI don't want pets in my house!!!!\n" << std::endl;
    for (int i = 0; i < 4; i++)
        delete stupid_array[i];
    return (0);
}