/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:22:08 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/08 15:15:28 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>      // std::vector

BitcoinExchange::BitcoinExchange(void) {
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
        this->pricesbydate = rhs.pricesbydate;
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
        //double val = atof(price.c_str());
        std::istringstream iss(price);
        double val;
        iss >> val;
        pricesbydate.insert(std::pair<std::string, double>(date, val));
   }
   file.close();
}

bool isValidInt(const std::string& str) {
    std::istringstream iss(str);
    float val;
    char c;
    if (!(iss >> val) || (iss >> c)) // Check for any extra characters
        return false;

    return val >= 0 && val <= 1000;
}
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(const std::string& str) {
    std::istringstream iss(str);
    int year, month, day;
    char separator;
    iss >> year >> separator >> month >> separator >> day;
    if (separator == '-' && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
        if (month == 2) {
            if (day <= 28)
                return true;
            if (day == 29 && isLeapYear(year))
                return true;
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            return day <= 30;
        } else {
            return true;
        }
    }
    return false;
}

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error, Opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::string date;
    std::string value;
    std::string delimiter = "|";
    size_t pos = 0;
    getline(file, line);
    while (getline(file, line)) {
        pos = line.find(delimiter);
        date = line.substr(0, pos);
        value = line.substr(pos + 1);

        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);

        double calc = 0;
        if (isValidDate(date)) {
            // must check if the number is valid (all digits in the string) and positive
            if (value[0]=='-') {
                std::cout << "Error: not a positive number." << std::endl;
                continue;
            }
            if (checkValue(value) == false) {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            if (!isValidInt(value)) {
                std::cout << "Error: too large a number." << std::endl;
                continue;
            }
            std::map<std::string, double>::iterator it;
            it = pricesbydate.lower_bound(date);
            double val = it->second;
            calc = val * atof(value.c_str());
            std::cout << date << " => " << value << " = " << calc << std::endl;
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }

    file.close();
}
bool BitcoinExchange::checkValue(const std::string& value) {
    int dotCount = 0;
    bool allowNegative = true;
    int i = 0;

    if (value[0] == '-') {
        if (!allowNegative)
            return false;
        allowNegative = false;
    }
    while (value[i]) {
        if (value[i] == '.') {
           dotCount++;
            if (dotCount > 1)
                return false;
        } else if (!std::isdigit(value[i])) {
            return false;
        }
        i++;
    }

    if (value.empty() || (value.size() == 1 && value[0] == '-'))
        return false;
    return true;
}
void BitcoinExchange::startPrincing() {
    readFromFileAndFillMap();
    processInputFile(this->_filename);
};