/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:00:44 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/11 15:20:16 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>
int main(void)
{
    Point const P(0,1);
    Point const A(-2,0);
    Point const B(2,0);
    Point const C(0,2);
    std::cout << bsp(A,B,C,P) << std::endl;
}
