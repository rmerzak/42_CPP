/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 19:00:55 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/29 16:47:55 by rmerzak          ###   ########.fr       */
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
    try
    {
        /* code */
        std::cout << *easyfind(vect, 3)<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}