/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:23 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/21 14:30:47 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Conversion
{
private:
    /* data */
public:
    Conversion(/* args */);
    Conversion(const Conversion &D);
    void ft_parsing(std::string str);
    void ft_conversion(std::string str);
    void ft_ToInt(std::string str);
    void ft_Tochar(std::string str);
    void ft_Tofloat(std::string str);
    void ft_ToDouble(std::string str);
    ~Conversion();
};

