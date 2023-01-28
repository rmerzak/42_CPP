/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:45:10 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/28 16:58:50 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main()
{
    std::string a = "hello a";
    std::string b = "world b";
    int x = 1;
    int y = 2;
    std::cout << max(5, 6) << std::endl;
    std::cout << min(5, 6) << std::endl;
    swap(a, b);
    swap(x, y);
    std::cout << "a = " << a << " | b = " << b << std::endl;
    std::cout << "x = " << x << " | y = " << y << std::endl;
}