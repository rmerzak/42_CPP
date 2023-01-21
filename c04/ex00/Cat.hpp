/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:13:22 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 16:31:57 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <string>
#include "Animal.hpp"

class Cat : public Animal
{

public:
    Cat();
    Cat(const Cat &D);
    Cat &operator=(const Cat &D);
    virtual ~Cat();
    void makeSound() const ;
};

#endif