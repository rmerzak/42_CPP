/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:52:55 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:43:32 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Destructor called inside WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat &D) : WrongAnimal(D)
{
    this->type = D.type;
}

WrongCat &WrongCat::operator=(const WrongCat &D)
{
    if (this == &D)
        return *this;
    std::cout << "Assignment operator called" << std::endl;
    this->type = D.type;
    return *this;
}


void WrongCat::makeSound() const
{
    std::cout << "WrongCat : moew moew" << std::endl;
}
