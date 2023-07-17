/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:13:19 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 16:34:35 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Destructor called inside Cat" << std::endl;
}

Cat::Cat(const Cat &D) :Animal()
{
    this->type = D.type;
}

Cat &Cat::operator=(const Cat &D)
{
    if (this == &D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->type = D.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Cat : moew moew" << std::endl;
}
