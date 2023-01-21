/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:45:00 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/09 12:10:23 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
    this->counter = 0;
    this->index = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::ADD()
{
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string DarkSecret;
    std::string Number;
    std::cout << "give the name = ";
    getline(std::cin, FirstName);
    if (std::cin.good() == false || FirstName.length() == 0 || FirstName.find_first_not_of(" \n\v\t\f\r"))
        return ;
    std::cout << "give the LastName = ";
    getline(std::cin, LastName);
    if (std::cin.good() == false || LastName.length() == 0 || LastName.find_first_not_of(" \n\v\t\f\r"))
        return ;
    std::cout << "give the NickName = ";
    getline(std::cin, NickName);
    if (std::cin.good() == false || NickName.length() == 0 || NickName.find_first_not_of(" \n\v\t\f\r"))
        return ;
    std::cout << "give the DarkSecret = ";
    getline(std::cin, DarkSecret);
    if (std::cin.good() == false || DarkSecret.length() == 0 || DarkSecret.find_first_not_of(" \n\v\t\f\r"))
        return ;
    std::cout << "give the Number = ";
    getline(std::cin, Number);
    if (std::cin.good() == false || Number.length() == 0 || Number.find_first_not_of(" \n\v\t\f\r"))
        return ;
    int i = this->counter % 8;
    members[i].setFirstName(FirstName);
    members[i].setLastName(LastName);
    members[i].setNickName(NickName);
    members[i].setDarkSecret(DarkSecret);
    members[i].setNumber(Number);
    this->counter++;
    if (this->index <= 7)
        this->index++;
}

void PhoneBook::DISPLAY()
{
    int i;

    i = 0;

    std::cout << "Displaying the saved contacts"<< std::endl;
    std::cout << "_____________________________________________"<< std::endl;
    std::cout << "|   index  |  name    | lastName | nickName |"<< std::endl;
    while (i < this->index)
    {
        std::cout << "|" << i + 1 << std::setw(10);
        members[i].to_string();
        i++;
    }
    std::cout << std::endl << std::endl;
}

void PhoneBook::SEARCH()
{
    int i;
    std::stringstream in;
    std::string input;
    DISPLAY();
    std::cout << "enter the id to look for i = ";
    getline(std::cin, input);
    in << input;
    in >> i;
    if (i > 0 && i < 9 && i <= this->index)
    {
        std::cout << "FirstName: " << members[i - 1].getFirstName()<<std::endl;
        std::cout << "Lastname: " << members[i - 1].getLastname()<<std::endl;
        std::cout << "NickName: " << members[i - 1].getNickName()<<std::endl;
        std::cout << "DarkSecret: " << members[i - 1].getDarkSecret()<<std::endl;
        std::cout << "Number: " << members[i - 1].getNumber()<<std::endl;
    }
    else {
        std::cout << "Error index not valid";
       return ;
    }
}