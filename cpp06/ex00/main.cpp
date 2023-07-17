/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:49:25 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/22 15:59:40 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
int main(int argc,char **argv) {
    if (argc == 2) {
        std::string str(argv[1]);
        Conversion c(str);
        c.ft_conversion();
    } else {
        std::cout << "nomber of argument: invalid";
    }
    return (1);
}