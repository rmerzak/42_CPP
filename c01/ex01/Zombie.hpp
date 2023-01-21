/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:19:19 by rmerzak           #+#    #+#             */
/*   Updated: 2022/12/04 13:59:47 by rmerzak          ###   ########.fr       */
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
        Zombie( void );
        ~Zombie( void );
        void set_name(std::string name);
        std::string get_name();
        void announce( void );
};
Zombie* zombieHorde( int N, std::string name );
#endif