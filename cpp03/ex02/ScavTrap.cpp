/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:01:03 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/13 20:42:07 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
ScavTrap::ScavTrap() : ClapTrap(100, 50, 20)
{
    std::cout << " constructor inside ScavTrap " << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
    std::cout << " constructor inside ScavTrap " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &D)
{
    if (this == &D)
        return *this;
    this->name = D.name;
    this->HitPoints = D.HitPoints;
    this->AtackDamage = D.AtackDamage;
    this->EnergyPoint = D.EnergyPoint;
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &D) {
        name = D.name;
        HitPoints = D.HitPoints;
        AtackDamage = D.AtackDamage;
        EnergyPoint = D.EnergyPoint;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->EnergyPoint > 0)
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << " ,causing " << this->AtackDamage << " points of damage!" << std::endl;
        this->EnergyPoint--;
    }
}
