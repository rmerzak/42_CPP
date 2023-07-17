/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:14:54 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/09 15:45:52 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) {
    this->name = name;
}

Zombie::Zombie( void) {
}

Zombie::~Zombie( ) {
    std::cout << this->name << ": " << "destroyed" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << this->name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
