/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 21:34:24 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/09 10:03:05 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Contact.hpp"
#include <iomanip>

Contact:: Contact(std::string firstname , std::string lastname, std::string nickname, std::string darksecret, int number)
{
    FirstName = firstname;
    LastName = lastname;
    NickName = nickname;
    DarkSecret = darksecret;
    Number = number;
}
Contact::~Contact ()
{
}
Contact::Contact ( void )
{
}
void Contact::setFirstName(std::string FirstName)
{
    this->FirstName = FirstName;
}
void Contact::setLastName(std::string LastName)
{
    this->LastName = LastName;
}
void Contact::setNickName(std::string NickName)
{
    this->NickName = NickName;
}
void Contact::setDarkSecret(std::string DarkSecret)
{
    this->DarkSecret = DarkSecret;
}
void Contact::setNumber(std::string Number)
{
    this->Number = Number;
}
std::string Contact::getFirstName()
{
    return FirstName;
}
std::string Contact::getLastname()
{
    return LastName;
}
std::string Contact::getNickName()
{
    return NickName;
}
std::string Contact::getDarkSecret()
{
    return DarkSecret;
}
std::string Contact::getNumber()
{
    return Number;
}

void Contact::to_string()
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string darkSecret;
    std::string number;

    firstName = this->FirstName;
    lastName = this->LastName;
    nickName = this->NickName;
    darkSecret = this->DarkSecret;
    number = this->Number;
    if (this->FirstName.length() >= 10)
        firstName = this->FirstName.substr(0, 9).append(".");
    if (this->LastName.length() >= 10)
        lastName = this->LastName.substr(0, 9).append(".");
    if (this->NickName.length() >= 10)
        nickName = this->NickName.substr(0, 9).append(".");
    if (this->DarkSecret.length() >= 10)
        darkSecret = this->DarkSecret.substr(0, 9).append(".");
    if (this->Number.length() >= 10)
        number = this->Number.substr(0, 9).append(".");
    std::cout << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName  << "|" << std::setw(10) << nickName  << "|" <<std::endl;
}