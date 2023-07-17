/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:13:19 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:42:57 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
Cat::Cat() : Animal("Cat")
{
    Br = new Brain();
    std::cout << "constructor called" << std::endl;
}

Cat::~Cat()
{
    delete Br;
    std::cout << "Destructor called inside Cat" << std::endl;
}

Cat::Cat(const Cat &D) :Animal()
{
    *this = D;
}

Cat &Cat::operator=(const Cat &D)
{
    if(this == &D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->type = D.type;
    Brain *B = new Brain();
    B->setBrain(D.Br->getBrain());
    this->Br = B;
    return *this;
}


void Cat::makeSound() const
{
    std::cout << "Cat : moew moew" << std::endl;
}
