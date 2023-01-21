/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:49:25 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/21 14:34:10 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include <iostream>
int main(int argc,char **argv) {
    if (argc == 2) {
        Conversion c;
        c.ft_parsing(argv[1]);
        c.ft_conversion(argv[1]);
    } else {
        std::cout << "nomber of argument: invalid";
    }
    return (1);
}