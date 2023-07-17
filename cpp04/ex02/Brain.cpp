/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 12:30:36 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:47:00 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(std::string id[100])
{
    std::cout << "constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = id[i];
    }
}

Brain::Brain()
{
    std::cout << "constructor called inside Brain" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = "hello there";
    }
}

Brain::~Brain()
{
        std::cout << "deconstructor called inside Brain" << std::endl;
}

Brain::Brain(const Brain &D)
{
    *this = D;
}

Brain &Brain::operator=(const Brain &D)
{
    std::cout << "Assignment operator called" << std::endl;
    if(this == &D)
        return *this;
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = D.ideas[i];
    }
    return *this;
}

std::string *Brain::getBrain(void)
{
    return this->ideas;
}

void Brain::setBrain(std::string id[100])
{
    for (int i = 0; i < 100; i++)
    {
        this->ideas[i] = id[i];
    }
}
