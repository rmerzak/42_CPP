/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:39:23 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/11 15:06:34 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
    //std::cout << this->y << std::endl;
    //std::cout << this->x << std::endl;
};

Point:: Point( Fixed const x, Fixed const y): x(x),y(y)
{
    //std::cout << this->y << std::endl;
    //std::cout << this->x << std::endl;
}

Point::~Point()
{
};

// Point::Point(const Point &P) {
//     this->x = P.x;
//     this->y = P.y;
// }

Fixed  Point::getX() const{
    return (this->x);
}
Fixed  Point::getY() const {
    return (this->y);
}