/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:22:11 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/14 14:54:56 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap x("Astro");
    ClapTrap y("Thor");

    x.attack(y.getName());
    y.takeDamage(11);
    std::cout << x.getEnergyPoint() << std::endl;
    std::cout << y.getEnergyPoint() << std::endl;
    std::cout << y.getHitPoint() << std::endl;
    y.beRepaired(1);
    std::cout << y.getEnergyPoint() << std::endl;
    std::cout << y.getHitPoint() << std::endl;
    y.takeDamage(1);

    return (0);
}