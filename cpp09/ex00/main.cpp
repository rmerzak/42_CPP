/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:32:14 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/18 16:26:39 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Error, could not open file" << std::endl;
        return 1;
    }
    BitcoinExchange bitcoin(argv[1]);
    bitcoin.startPrincing();
    return (0);
}