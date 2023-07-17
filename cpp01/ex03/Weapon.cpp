/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:34:29 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/10 15:20:22 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
    this->type = type;
}

Weapon::~Weapon()
{
}
Weapon::Weapon()
{
}

std::string Weapon::getType() const {
    return (this->type);
}

void Weapon::setType(std::string type) {
    this->type = type;
}