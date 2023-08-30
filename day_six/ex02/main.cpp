/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 05:48:22 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/20 06:18:09 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

Base    *generate(void)
{
    switch (rand() % 3 + 1)
    {
    case 1:
        std::cout << "Class A generated!" << std::endl;
        return (new A);
        break;
    case 2:
        std::cout << "Class B generated!" << std::endl;
        return (new B);
        break;
    case 3:
        std::cout << "Class C generated!" << std::endl;
        return (new C);
        break;
    }
    return (new A);
}

void    identify(Base* p)
{
    if (dynamic_cast<A *>(p))
    {
        std::cout << "Class A identified by pointer" << std::endl;
        return ;
    }
    if (dynamic_cast<B *>(p))
    {
        std::cout << "Class B identified by pointer" << std::endl;
        return ;
    }
    if (dynamic_cast<C *>(p))
    {
        std::cout << "Class C identified by pointer" << std::endl;
        return ;
    }
}

void    identify(Base& p)
{
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Class A identified by reference" << std::endl;
        (void)a;
        return ;
    }
    catch(const std::exception& e) {
        (void)e;
    }
    try {
        B &b = dynamic_cast<B &>(p);
        std::cout << "Class B identified by reference" << std::endl;
        (void)b;
        return ;
    }
    catch(const std::exception& e) {
        (void)e;
    }
    try {
        C &c = dynamic_cast<C &>(p);
        std::cout << "Class C identified by reference" << std::endl;
        (void)c;
        return ;
    }
    catch(const std::exception& e) {
        (void)e;
    }
}

int main(void)
{
    srand(time(0));

    Base * base = generate();
    identify(base);
    identify(*base);
    delete base;

    base = generate();
    identify(base);
    identify(*base);
    delete base;

    base = generate();
    identify(base);
    identify(*base);
    delete base;
    return (0);
}