/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:26 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/22 15:59:08 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
Conversion::Conversion(std::string _str)
{
    this->str = _str;
}

Conversion::Conversion()
{
}

Conversion::Conversion(const Conversion &D) {
    *this = D;
}

Conversion &Conversion::operator=(const Conversion &D) {
    this->str = D.str;
    return *this;
}

int Conversion::ft_ToInt() {
    return static_cast<int>(ft_Tofloat());
}

double Conversion::ft_ToDouble() {
    return static_cast<double>(ft_Tofloat());
}

char Conversion::ft_Tochar() {
    return static_cast<char>(ft_Tofloat());
}

float Conversion::ft_Tofloat() {
    return atof(this->str.c_str());
}

Conversion::~Conversion()
{
}

void Conversion::ft_conversion() {
    const int vint = this->ft_ToInt();
    const float vfloat = this->ft_Tofloat();
    const double vdouble= this->ft_ToDouble();
    const char vchar = this->ft_Tochar();

    if (vfloat < CHAR_MIN || vfloat > CHAR_MAX || isnan(vfloat)) {
		std::cout << "char: impossible" << std::endl;
	} else if (isprint(vchar)) {
		std::cout << "char: '" << vchar << "'" << std::endl;
	} else {
		std::cout << "char: non displayable" << std::endl;
	}

	if (vint < INT_MIN || vint > INT_MAX || isnan(vfloat)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << vint << std::endl;
	}


	if (vfloat - vint == 0) {
		std::cout << "float: " << vfloat << ".0f" << std::endl;
		std::cout << "double: " << vdouble << ".0" << std::endl;
	} else {
		std::cout << "float: " << vfloat << "f" << std::endl;
		std::cout << "double: " << vdouble << std::endl;
	}
}