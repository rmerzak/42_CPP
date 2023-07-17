/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:19:23 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/09 17:59:37 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *Allocate = new Zombie[N];
    int i;

    i = 0;
    while (i < N)
    {
        Allocate[i].set_name(name);
        i++;
    }
    return (Allocate);
}