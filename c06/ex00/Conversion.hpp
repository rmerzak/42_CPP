/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:23 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/22 15:59:27 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cmath>
class Conversion
{
private:
    std::string str;
public:
    Conversion();
    Conversion(std::string _str);
    Conversion(const Conversion &D);
    Conversion &operator=(const Conversion &D);
    void ft_conversion();
    int ft_ToInt();
    char ft_Tochar();
    float ft_Tofloat();
    double ft_ToDouble();
    ~Conversion();
};
