/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:00:41 by rmerzak           #+#    #+#             */
/*   Updated: 2022/11/22 21:07:12 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>
Fixed::Fixed()
{
    this->num = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(int n)
{
    this->num = n * (1 << 8);
}
Fixed::Fixed(const float num)
{
    this->num = roundf(num * (1 << 8));
}

Fixed::Fixed(const Fixed &p)
{
    num = p.num;
}

void Fixed::operator=(const Fixed &D)
{
    this->num = D.num;
}

void Fixed::setRawBits(int const raw)
{
    this->num = raw;
}
int Fixed::getRawBits(void) const
{
    return this->num;
}
int Fixed::toInt(void) const
{
    return ((int)this->num / (1 << 8));
}
float Fixed::toFloat(void) const
{
    return ((float)this->num / (1 << 8));
}

std::ostream &operator<<(std::ostream &output, const Fixed &D)
{
    output << D.toFloat();
    return output;
}

Fixed Fixed::operator+(Fixed const &obj)
{
    Fixed res;
    res.num = this->num + obj.num;
    return res;
}

Fixed Fixed::operator*(Fixed const &obj)
{
    Fixed res;
    res.num = (this->num * obj.num) / (1 << nbits);
    return res;
}

Fixed Fixed::operator/(Fixed const &obj)
{
    Fixed res;
    res.num = ((float)this->num / obj.num) * (1 << nbits);
    return res;
}

Fixed Fixed::operator-(Fixed const &obj)
{
    Fixed res;
    res.num = this->num - obj.num;
    return res;
}

Fixed &Fixed::operator++()
{
    this->num++;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    operator++();
    return old;
}
Fixed &Fixed::operator--()
{
    this->num--;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    operator--();
    return old;
}

bool Fixed::operator==(const Fixed &obj1) const
{
    if (this->num == obj1.num)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &obj1) const
{
    return !operator==(obj1);
}
bool Fixed::operator<(const Fixed &obj1) const
{
    if (this->num < obj1.num)
        return true;
    return false;
}

bool Fixed::operator>(const Fixed &obj1) const
{
    if (this->num > obj1.num)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &obj1) const
{
    return !operator>(obj1);
}
bool Fixed::operator>=(const Fixed &obj1) const
{
    return !operator<(obj1);
}

const Fixed &Fixed::min(const Fixed &obj1, const Fixed &obj2)
{
    if (obj1 < obj2)
        return obj1;
    else
        return obj2;
}

const Fixed &Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
     if (obj1 > obj2)
        return obj1;
    else
        return obj2;
}

Fixed &Fixed::min(Fixed &obj1, Fixed &obj2)
{
     if (obj1 < obj2)
        return obj1;
    else
        return obj2;
}

Fixed &Fixed::max(Fixed &obj1, Fixed &obj2)
{
    if (obj1 > obj2)
        return obj1;
    else
        return obj2;
}
