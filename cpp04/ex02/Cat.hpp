/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:13:22 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:42:47 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal
{
protected:
    std::string type;

private:
    Brain *Br;

public:
    Cat();
    Cat(const Cat &D);
    Cat &operator=(const Cat &D);
    ~Cat();
    void makeSound() const;
};

#endif