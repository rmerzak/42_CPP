/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:53:01 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 18:43:37 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
protected:
    std::string type;

public:
    WrongCat();
    WrongCat(const WrongCat &D);
    WrongCat &operator=(const WrongCat &D);
    ~WrongCat();
    std::string getType(void) const;
    void makeSound() const ;
};
#endif