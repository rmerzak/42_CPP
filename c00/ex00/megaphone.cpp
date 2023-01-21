/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 20:26:06 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/09 09:46:26 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                // touper function return ASCII code for uppercase alphabets
                // for non alphabets => ascii code of the input
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            i++;
        }
    }
    std:: cout << std::endl;
    return (0);
}
