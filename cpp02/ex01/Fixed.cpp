/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:00:41 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/11 15:37:30 by rmerzak          ###   ########.fr       */
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

Fixed::Fixed(const int n)
{
    std::cout << "int constructor called" << std::endl;
    this->num = n * (1 << 8);
}
Fixed::Fixed(const float num) {

    std::cout << "float constructor called" << std::endl;
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
int Fixed::toInt( void ) const {
    return ((int)this->num / (1 << 8));
}
float Fixed::toFloat( void ) const {
    return ((float)this->num / (1 << 8));
}

std::ostream &operator<<(std::ostream &output, const Fixed &D) {
    output << D.toFloat();
    return output;
}