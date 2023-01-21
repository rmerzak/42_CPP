/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:22:11 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/11 22:10:53 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
        ScavTrap x("Astro");
        ScavTrap y("Thor");

        x.attack(y.getName());
        y.takeDamage(3);
        std::cout << x.getEnergyPoint() << std::endl;
        std::cout << y.getEnergyPoint() << std::endl;
        std::cout << y.getHitPoint() << std::endl;
        y.beRepaired(1);
        std::cout << y.getEnergyPoint() << std::endl;
        std::cout << y.getHitPoint() << std::endl;
        y.takeDamage(9);
        std::cout << y.getEnergyPoint() << std::endl;
        std::cout << y.getHitPoint() << std::endl;
        x.guardGate();
        y.takeDamage(7);
    return (0);
}