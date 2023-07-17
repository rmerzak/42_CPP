/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:52:52 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/16 17:28:17 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>
class WrongAnimal
{
private:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &D);
    WrongAnimal &operator=(const WrongAnimal &D);
    virtual ~WrongAnimal();
    std::string getType(void) const;
    void makeSound() const;
};

#endif
