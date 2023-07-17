/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 23:00:59 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/13 17:20:13 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>
class ScavTrap : public ClapTrap
{

public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &D);
    ScavTrap &operator=(const ScavTrap &D);
    ~ScavTrap();
    void guardGate();
    void attack(const std::string &target);
};
#endif