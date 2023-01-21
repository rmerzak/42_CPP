/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:52:46 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/13 22:43:58 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>
WrongAnimal::WrongAnimal()
{
}
WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
    std::cout << "constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor called inside WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &D) {
    this->type = D.type;
}


WrongAnimal &WrongAnimal::operator=(const WrongAnimal &D)
{
    if (this == &D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->type = D.type;
    return *this;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal : sound none" << std::endl;
}

