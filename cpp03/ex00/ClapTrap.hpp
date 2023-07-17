/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:22:06 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/13 16:31:53 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string     name;
    unsigned int    HitPoints;
    unsigned int    EnergyPoint;
    unsigned int    AtackDamage;

public:
    ClapTrap(std::string name);
    ClapTrap(std::string name, unsigned int HitPoints, unsigned int EnergyPoint, unsigned int AtackDamage);
    ClapTrap();
    ClapTrap(const ClapTrap &D);
    ClapTrap &operator=(const ClapTrap &D);
    ~ClapTrap();
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    std::string getName(void);
    int getHitPoint(void);
    int getEnergyPoint(void);
    int getAtackDamage(void);
};
#endif