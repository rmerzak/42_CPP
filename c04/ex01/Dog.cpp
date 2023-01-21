/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:13:24 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:41:10 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
Dog::Dog() : Animal("Dog")
{
    Br = new Brain();
    std::cout << "constructor called" << std::endl;
}

Dog::~Dog()
{
    delete Br;
    std::cout << "Destructor called inside Dog" << std::endl;
}

Dog::Dog(const Dog &D)
{
   *this = D;
}

Dog &Dog::operator=(const Dog &D)
{
    if (this == &D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->type = D.type;
    Brain *B = new Brain();
    B->setBrain(D.Br->getBrain());
    this->Br = B;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Dog : hoew hoew" << std::endl;
}
