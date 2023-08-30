/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:04:18 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 13:22:11 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap clapizinho("Lindinho");

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
    return (0);
}