/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:00:41 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/11 16:01:33 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <math.h>
Fixed::Fixed()
{
    this->num = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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
    std::cout << "Copy constructor called" << std::endl;
}

void Fixed::operator=(const Fixed &D)
{
    this->num = D.num;
    std::cout << "Copy assignment operator called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    this->num = raw;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
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
    return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(Fixed const &obj)
{
    return (this->toFloat() / obj.toFloat());
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
