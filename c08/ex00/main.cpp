/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:00:55 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/27 19:35:09 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<float> vect;

    vect.push_back(1);
    vect.push_back(5);
    vect.push_back(8.5);
    vect.push_back(3);
    vect.push_back(22);
    vect.push_back(0);
    vect.push_back(6);
    vect.push_back(6);
    vect.push_back(3);

    easyfind(vect, 8.5);
}