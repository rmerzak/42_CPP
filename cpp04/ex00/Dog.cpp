/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:13:24 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 16:34:27 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Destructor called inside Dog" << std::endl;
}

Dog::Dog(const Dog &D) :Animal()
{
    type = D.type;
}

Dog &Dog::operator=(const Dog &D)
{
    if (this==&D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->type = D.type;
    return *this;
}


void Dog::makeSound() const
{
    std::cout << "Dog : hoew hoew" << std::endl;
}
