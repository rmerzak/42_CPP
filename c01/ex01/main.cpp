/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:19:09 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/09 18:03:50 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
    Zombie  *Allocate;
    int     N = 5;
    int     i = 0;
    Allocate = zombieHorde(N, "hello");
    while (i < N)
    {
        Allocate[i].announce();
        i++;
    }
    delete [] Allocate;
}