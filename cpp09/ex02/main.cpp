/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:04:32 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/16 18:35:48 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>
#include "PmergeMe.hpp"
int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    PmergeMe pmergeMe(argv);
    return 0;
}
