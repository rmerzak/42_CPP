/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 21:24:38 by rmerzak           #+#    #+#             */
/*   Updated: 2022/12/04 14:14:20 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

int main(int argc, char **argv)
{
    std::string myText;
    int i, s;
    if (argc != 4 || !std::string(argv[2]).length() || !std::string(argv[3]).length())
    {
        std::cout << "error params" << std::endl;
        return 0;
    }
    else
    {
        std::ifstream MyFile(argv[1]);
        std::ofstream MyReplaceFile((std::string(argv[1]) + ".replace").c_str());
        if (MyFile.fail() || MyReplaceFile.fail())
        {
            std::cout << "error file" << std::endl;
            return (1);
        }
        while (getline(MyFile, myText))
        {
            i = 0;
            s = 0;
            while (i != -1)
            {
                i = myText.find(argv[2], s);
                if(i != -1 && std::string(argv[2]) == std::string(argv[3])) {
                    s = i + std::string(argv[2]).length();
                }
                if (i != -1 && std::string(argv[2]) != std::string(argv[3]))
                {
                    myText.erase(i, std::string(argv[2]).length());
                    myText.insert(i, argv[3]);
                }
            }
            if(!MyFile.eof())
            {
                myText.append("\n");
            }
            MyReplaceFile << myText;
        }
        MyFile.close();
        MyReplaceFile.close();
    }
    return (0);
}

// find => erase ==> insert