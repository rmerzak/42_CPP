/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:19:14 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/13 20:42:38 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :  FragTrap("none_clap_name"), ScavTrap("none_clap_name"){
    std::cout << "DiamondTrap default constrector called" << std::endl;
    this->name = "none";
    this->FragTrap:: HitPoints = 100;
    this->FragTrap::AtackDamage = 30;
    this->ScavTrap::EnergyPoint = 50;
}
DiamondTrap::DiamondTrap(std::string name) : FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
    std::cout << "DiamondTrap constrector called" << std::endl;
    this->name = name;
    this->FragTrap:: HitPoints = 100;
    this->FragTrap::AtackDamage = 30;
    this->ScavTrap::EnergyPoint = 50;
}

DiamondTrap::DiamondTrap(const DiamondTrap &D):  FragTrap(D) , ScavTrap(D){
    this->name = D.name;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap deconstrector called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &D) {
    if (this == &D)
        return *this;
    this->FragTrap::operator=(D);
    this->ScavTrap::operator=(D);
    this->name = D.name;
    return *this;
}

std::string DiamondTrap::getName(void) {
    return this->name;
}

void DiamondTrap::setName(std::string n) {
    this->name = n;
}

void DiamondTrap::attack(const std::string &target)
{
    std::cout << " inside DiamondTrap ";
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap : name is "<< name <<" and ClapTrap name is " << ScavTrap::getName() << std::endl;
}