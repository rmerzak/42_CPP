/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:11:17 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/10 12:00:29 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int main (void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR;
    std::string &stringRef = str;

    stringPTR = &str;
    std::cout << &str << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringRef << std::endl;

    std::cout << str << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringRef << std::endl;
}