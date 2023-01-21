/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:39:28 by rmerzak           #+#    #+#             */
/*   Updated: 2022/11/22 18:57:56 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;
public:
    Point();
    ~Point();
    Point(Fixed const x,Fixed const y);
    // Point(const Point &P);
    // void operator=(const Point &P);
    Fixed  getX(void) const;
    Fixed  getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
Fixed *ft_calcul(Point const X, Point const Y, Point const Z, Point const t);