/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:23 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/21 19:40:52 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cmath>
class Conversion
{
private:
    std::string str;
    char c;
    int i;
    float f;
    double d;
public:
    Conversion();
    Conversion(std::string _str);
    Conversion(const Conversion &D);
    Conversion &operator=(const Conversion &D);
    void ft_conversion();
    //////////////////////////////////
    void ft_ToInt();
    void ft_Tochar();
    void ft_Tofloat();
    void ft_ToDouble();
    ///////////////////////////////////
    void ft_parsing(char *str);
    //checks////////////////////////////
    bool checkInt();
    bool checkDouble();
    bool checkChar();
    bool checkFloat();
    bool checkConst();
    ////////////////////////////////////
    ~Conversion();
};

