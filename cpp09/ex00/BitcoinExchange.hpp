/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:50:50 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/19 18:02:50 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
class BitcoinExchange {
    private:
        std::string _filename;
        std::map<std::string, double> pricesbydate;
    public:
        BitcoinExchange(void);
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
        void readFromFileAndFillMap();
        void printPricesByDate();
        void checkFormatDate(std::string date);
        void processInputFile(const std::string& filename);
        void startPrincing();
        bool checkValue(const std::string& value);
};

#endif