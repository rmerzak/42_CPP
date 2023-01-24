/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:01:14 by rmerzak           #+#    #+#             */
/*   Updated: 2023/01/23 22:29:37 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <iostream>

Base * generate(void) {
    srand(time(0));
    int randomNumber = (rand() % 3) + 1;
    switch (randomNumber)
    {
    case 1:
        return new A;
        break;
    case 2:
        return new B;
        break;
    case 3:
        return new C;
        break;
    default:
        break;
    }
    return NULL;
}

void identify(Base* p) {
     if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}


void identify(Base& p) {
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(std::bad_cast const&)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch(std::bad_cast const&)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch(std::bad_cast const&)
            {
                std::cerr << "error cast "<< '\n';
            }
        }
    }
}

int main() {
    Base* b = generate();
    identify(b);
    std::cout << std::endl;
    identify(*b);
    delete b;
}