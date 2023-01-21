/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:26 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/21 20:40:16 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>
Conversion::Conversion(std::string _str):str(_str)
{

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

void Conversion::ft_ToInt() {
    try {
        int i = std::stoi(this->str.c_str());
        std::cout <<"int: " << static_cast<int>(i) << std::endl;
    } catch(...) {
        std::cerr << "int: impossible" << std::endl;
    }
}

void Conversion::ft_ToDouble() {
    try {
        double i = std::stod(this->str.c_str());
        std::cout <<std::fixed <<std::cout.precision(1)<<"double: "<<static_cast<double>(i)<<std::endl;
    } catch(...) {
        std::cerr << "double: impossible" << std::endl;
    }
}

void Conversion::ft_Tochar() {
    try {
        int i = std::stoi(this->str.c_str());
        if (isprint(i) == true)
        {
            std::cout <<"char: " << static_cast<char>(i) << std::endl;
        }
        else
        {
            std::cout <<"char: Non displayable" << static_cast<char>(i) << std::endl;

        }
    } catch(...) {
        std::cerr << "char: impossible" << std::endl;
    }
}

void Conversion::ft_Tofloat() {
    try {
        double i = std::stof(this->str.c_str());
        std::cout <<std::fixed <<std::cout.precision(1)<<"float: "<<static_cast<float>(i)<<std::endl;
    } catch(...) {
        std::cerr << "float: impossible" << std::endl;
    }
}

Conversion::~Conversion()
{
}

void Conversion::ft_conversion() {
    this->ft_Tochar();
    this->ft_ToInt();
    this->ft_Tofloat();
    this->ft_ToDouble();
    /*const int vint = this->ft_ToInt();
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
	}*/
}
