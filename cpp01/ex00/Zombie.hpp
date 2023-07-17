/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:14:58 by rmerzak           #+#    #+#             */
/*   Updated: 2022/12/04 13:59:20 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie( std::string name );
        Zombie();
        ~Zombie();
        void announce( void );
};
Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif