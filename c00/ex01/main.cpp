/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:07:32 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/08 11:26:16 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

#include <string>

int main()
{
    PhoneBook           phone;
    std::string         choix;
    while(1)
    {
        std::cout << "Menu:" <<std::endl;
        std::cout << "    to add a new contact enter ADD" <<std::endl;
        std::cout << "    to shearch a contact enter SEARCH" <<std::endl;
        std::cout << "    to exit(0) a contact enter EXIT" <<std::endl;
        std::cout << "chose = ";
        getline(std::cin, choix);
        if (std::cin.eof())
            return (0);
        if (!choix.compare("ADD"))
            phone.ADD();
        else if (!choix.compare("SEARCH"))
            phone.SEARCH();
        else if(!choix.compare("EXIT"))
            break ;
    }
    return 0;
}