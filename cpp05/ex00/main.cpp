/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:59:23 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 14:36:56 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include <iostream>
int main(){
    try {
    Bureaucrat a("john", 11);
    Bureaucrat b;
    //b = a;
    //a.ft_increment();
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    }
    catch(std::exception &e) {
        std::cout<< e.what() << std::endl;
    }
}