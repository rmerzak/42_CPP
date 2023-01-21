/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:13:27 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:43:24 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
protected:
    std::string type;
private:
    Brain *Br;
public:
    Dog();
    Dog(const Dog &D);
    Dog &operator=(const Dog &D);
    ~Dog();
    void makeSound() const ;
};

#endif