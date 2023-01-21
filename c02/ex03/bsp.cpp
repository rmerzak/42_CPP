/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:39:19 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/11 15:22:11 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <math.h>

Fixed *ft_calcul(Point const X, Point const Y, Point const Z, Point const t)
{
    Fixed Xx = X.getX();
    Fixed Xy = X.getY();
    Fixed Yx = Y.getX();
    Fixed Yy = Y.getY();
    Fixed Zx = Z.getX();
    Fixed Zy = Z.getY();
    Fixed tx = t.getX();
    Fixed ty = t.getY();

    Fixed *w1 = new Fixed(((Xx * (Zy - Xy) + (ty - Xy) * (Zx - Xx) - tx * (Zy - Xy)) / ((Yy - Xy) * (Zx - Xx) - (Yx - Xx) * (Zy - Xy))));
    return w1;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed ay = a.getY();
    Fixed by = b.getY();
    Fixed cy = c.getY();
    Fixed pointy = point.getY();
    Fixed *w1 = ft_calcul(a, b, c, point);
    Fixed *w2 = new Fixed((pointy - ay - w1->operator*(by - ay)) / (cy - ay));
    if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) > 1)
        return (true);
    return (false);
}

// Fixed *get_w1(Point const a, Point const b, Point const c, Point const p) {
//     Fixed Ax = a.getX();
//     Fixed Ay = a.getY();
//     Fixed Bx = b.getX();
//     Fixed By = b.getY();
//     Fixed Cx = c.getX();
//     Fixed Cy = c.getY();
//     Fixed Px = p.getX();
//     Fixed Py = p.getY();

//     Fixed numerator = (Ax * (Cy - Ay)) + (Py - Ay) * (Cx - Ax) - Px * (Cy - Ay);
//     Fixed denominator = (By - Ay) * (Cx - Ax) - (Bx - Ax) * (Cy - Ay);
//     Fixed *w1 = new Fixed(numerator / denominator);

//     return (w1);
// }

// Fixed *get_w2(Fixed w1, Point const a, Point const b, Point const c, Point const p) {
//     Fixed Ay = a.getY();
//     Fixed By = b.getY();
//     Fixed Cy = c.getY();
//     Fixed Py = p.getY();

//     Fixed numerator = Py - Ay - w1 * (By - Ay);
//     Fixed denominator = Cy - Ay;
//     Fixed result = numerator / denominator;
//     Fixed *w2 = new Fixed(result);

//     return (w2);
// }

// bool bsp(Point const a, Point const b, Point const c, Point const p) {
//     Fixed *w1 = get_w1(a, b, c, p);
//     Fixed *w2 = get_w2(*w1, a, b, c, p);

//     bool ret = true;

//     if (*w1 > 0 && *w2 > 0 && (*w1 + *w2) < 1)
//         ret = true;
//     else
//         ret = false;
//     delete w1;
//     delete w2;
//     return (ret);