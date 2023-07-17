/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:00:38 by rmerzak           #+#    #+#             */
/*   Updated: 2022/11/20 17:01:13 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
private:
    int num;
    const static int nbits = 8;

public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed &p);
    ~Fixed();
    void operator=(const Fixed &D);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    friend std::ostream &operator<<(std::ostream &output, const Fixed &D);
    Fixed operator+(Fixed const &obj);
    Fixed operator-(Fixed const &obj);
    Fixed operator*(Fixed const &obj);
    Fixed operator/(Fixed const &obj);
    bool operator==(const Fixed &obj1) const;
    bool operator!=(const Fixed &obj1) const;
    bool operator<(const Fixed &obj1) const;
    bool operator>(const Fixed &obj1) const;
    bool operator<=(const Fixed &obj1) const;
    bool operator>=(const Fixed &obj1) const;
    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);
    static const Fixed &min(const Fixed &obj1, const Fixed &obj2);
    static const  Fixed &max(const Fixed &obj1, const Fixed &obj2);
    static Fixed &min(Fixed &obj1, Fixed &obj2);
    static Fixed &max(Fixed &obj1, Fixed &obj2);
};