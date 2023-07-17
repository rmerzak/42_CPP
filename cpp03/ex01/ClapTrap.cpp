/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:22:02 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/13 20:41:34 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "Default";
    this->HitPoints = 10;
    this->EnergyPoint = 10;
    this->AtackDamage = 0;
    std::cout << "Default constructor called " << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int HitPoints, unsigned int EnergyPoint, unsigned int AtackDamage)
{
    this->name = name;
    this->HitPoints = HitPoints;
    this->EnergyPoint = EnergyPoint;
    this->AtackDamage = AtackDamage;
}

ClapTrap::ClapTrap(unsigned int HitPoints, unsigned int EnergyPoint, unsigned int AtackDamage)
{
    this->HitPoints = HitPoints;
    this->EnergyPoint = EnergyPoint;
    this->AtackDamage = AtackDamage;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->HitPoints = 10;
    this->EnergyPoint = 10;
    this->AtackDamage = 0;
    std::cout << "constructor by name is called " << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &D)
{
    name = D.name;
    EnergyPoint = D.EnergyPoint;
    HitPoints = D.HitPoints;
    AtackDamage = D.AtackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &D)
{
    if (this == &D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->name = D.name;
    this->EnergyPoint = D.EnergyPoint;
    this->HitPoints = D.HitPoints;
    this->AtackDamage = D.AtackDamage;
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->EnergyPoint > 0)
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << " ,causing " << this->AtackDamage << " points of damage!" << std::endl;
        this->EnergyPoint--;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyPoint > 0)
    {
        this->HitPoints += amount;
        std::cout << "ClapTrap " << this->name << "take amount " << amount << "of hitpoint!" << std::endl;
        this->EnergyPoint--;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoints > 0)
    {
        if (amount >= this->HitPoints) {
            this->HitPoints = 0;
            std::cout << "ClapTrap " << this->name << " is dead!" << std::endl;
        }
        else{
            this->HitPoints -= amount;
            std::cout << "ClapTrap " << this->name << " take Damage " << amount << " of hitpoint!" << std::endl;
        }
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " already is dead!" << std::endl;
    }
}

std::string ClapTrap::getName()
{
    return this->name;
}

int ClapTrap::getHitPoint()
{
    return this->HitPoints;
}
int ClapTrap::getEnergyPoint()
{
    return this->EnergyPoint;
}
int ClapTrap::getAtackDamage()
{
    return this->AtackDamage;
}