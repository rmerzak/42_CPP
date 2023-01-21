/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:03:34 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/13 22:37:10 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("empty")
{
    std::cout << "constructor called" << std::endl;
}

Animal::Animal(std::string type) {
    this->type = type;
}

Animal::~Animal()
{
    std::cout << "Destructor called inside Animal" << std::endl;
}

Animal::Animal(const Animal &D)
{
    *this = D;
}

Animal &Animal::operator=(const Animal &D)
{
    if (this == &D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->type = D.type;
    return *this;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound() const
{
    std::cout << "Animal no sound defined" << std::endl;
}