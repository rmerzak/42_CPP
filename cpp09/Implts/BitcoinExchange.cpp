/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:22:08 by rmerzak           #+#    #+#             */
/*   Updated: 2023/07/17 16:31:41 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/BitcoinExchange.hpp"
#include <cstdlib>
BitcoinExchange::BitcoinExchange() {
}
BitcoinExchange::BitcoinExchange(std::string filename) : _filename(filename) {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
    *this = src;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs) {
    if (this != &rhs) {
        this->_pricesbydate = rhs._pricesbydate;
    }
    return *this;
}
void BitcoinExchange::readFromFileAndFillMap() {
    std::ifstream file("assets/data.csv");
    std::string line;
    std::string date;
    std::string price;
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    if (file.fail()) {
        std::cout << "Error, Opening csv file." << std::endl;
        exit(1);
    }
    getline(file, line);
    while(!file.eof()) {
        getline(file, line);
        pos = line.find(delimiter);
        date = line.substr(0, pos);
        price = line.substr(pos + 1, line.length());
        double val = atof(price.c_str());
        _pricesbydate.insert(std::pair<std::string, double>(date, val));
   }
   file.close();
   return;
}
void BitcoinExchange::startPrincing() {
    readFromFileAndFillMap();
    
}