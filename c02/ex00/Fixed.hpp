/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:00:38 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/11 16:08:49 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
    private:
        int num;
        const static int nbits = 8;
    public:
        Fixed();
        Fixed(int num);
        Fixed(const Fixed &p);
        ~Fixed();
        void operator = (const Fixed &D);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
#endif