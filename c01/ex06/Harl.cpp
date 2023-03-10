/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:39:45 by rmerzak           #+#    #+#             */
/*   Updated: 2022/12/04 14:24:01 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger."<< std::endl <<"I really do" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. "<< std::endl <<"You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl <<"I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::none( void ) {
}

void Harl::complain(std::string level) {
    int i;
    void (Harl::*function[5])(void) = {&Harl::none, &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    i = (level == "DEBUG") * 1 + (level == "INFO") * 2 + (level == "WARNING") * 3  + (level == "ERROR") * 4;
    switch (i)
    {
        case 1:
            (this->*function[i++])();
        case 2:
            (this->*function[i++])();
        case 3:
            (this->*function[i++])();
        case 4:
            (this->*function[i])();
            break;
        default:
            (this->*function[0])();
            break;
    }
}