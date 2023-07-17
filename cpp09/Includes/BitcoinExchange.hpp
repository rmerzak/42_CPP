/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:20:29 by rmerzak           #+#    #+#             */
/*   Updated: 2023/07/17 16:11:33 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BITCOINEXCHANGE_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <map>
class BitcoinExchange {
    private:
        std::map<std::string, double> _pricesbydate;
        const std::string _filename;
    public:
        void readFromFileAndFillMap();
        void printPricesByDate();
        void checkFormatDate(std::string date);
        void startPrincing();
        BitcoinExchange(void);
        BitcoinExchange(std::string filename);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        BitcoinExchange &operator=(const BitcoinExchange &rhs);
};

#endif