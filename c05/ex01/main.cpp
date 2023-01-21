/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:38:24 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/20 15:05:01 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

int main() {
   try {
    Bureaucrat a("john", 1);
    Form b("Form", 7, 6);
    std::cout << b << std::endl;
    b.beSigned(a);
    std::cout << b << std::endl;
    a.signForm(b);
    }
    catch(std::exception &e) {
        std::cout<< e.what() << std::endl;
    }

    return 1;
}