/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:22:11 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/12 21:18:51 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap dt("hero");
    DiamondTrap dt2("hero2");
    DiamondTrap dt3;
    dt3 = dt2;

    dt.whoAmI();
    dt.attack("enemy");

    dt3.whoAmI();
    dt3.attack("enemy2");
}