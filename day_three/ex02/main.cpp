/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:04:18 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 13:38:24 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap clapizinho("Lindinho");

    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.attack("Invejosa");
    clapizinho.takeDamage(5);
    clapizinho.beRepaired(5);
    clapizinho.high_fives_guys();
    clapizinho.high_fives_guys();
    clapizinho.high_fives_guys();
    clapizinho.high_fives_guys();
    clapizinho.high_fives_guys();
    return (0);
}