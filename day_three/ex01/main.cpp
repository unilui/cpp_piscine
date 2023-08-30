/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 < lufelip2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:04:18 by lufelip2          #+#    #+#             */
/*   Updated: 2023/07/16 13:34:13 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap    clapizinho("lindinho");
    
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
    clapizinho.guardGate();
    clapizinho.guardGate();
    clapizinho.guardGate();
    clapizinho.guardGate();
    return (0);
}