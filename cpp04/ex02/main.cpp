/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:06:37 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:48:25 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    Dog *dog = new Dog();
    Dog *dog01 = new Dog(*dog);
    Cat *cat = new Cat();
    Cat *cat01 = new Cat(*cat);
    Animal *array[4] = {dog, dog01,cat, cat01};
    for (int i = 0; i < 4; i++)
        array[i]->makeSound();
    for (int i = 0; i < 4; i++)
        delete array[i];
    return 0;
}