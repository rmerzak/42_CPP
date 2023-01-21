/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:42:59 by rmerzak           #+#    #+#             */
/*   Updated: 2022/10/09 12:01:09 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    this->_accountIndex = this->_nbAccounts;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_nbAccounts++;
    this->_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" <<this->_accountIndex << ";";
    std::cout << "amount:" <<this->_amount << ";";
    std::cout << "created" <<std::endl;
}
Account::Account( void )
{

}
Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" <<this->_accountIndex << ";amount:" <<this->_amount << ";closed" <<std::endl;
}

int Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals( void)
{
    return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:"<< _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}
void Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" <<this->_nbWithdrawals << std::endl;
}


void Account::makeDeposit( int deposit)
{
    int temp;

    temp = this->_amount;
    this->_nbDeposits++;
    this->_amount += deposit;
    _totalNbDeposits++;
    _totalAmount += deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << temp << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount( void ) const
{
    if (this->_amount >= 0)
        return (1);
    else
        return (0);
}

bool Account::makeWithdrawal( int withdrawal)
{
    int temp;
    temp = this->_amount;
    if (checkAmount() && this->_amount > withdrawal)
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        this->_totalAmount -= withdrawal;
         Account::_displayTimestamp();
         std::cout << "index:" << this->_accountIndex << ";p_amount:" << temp << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" <<this->_nbWithdrawals << std::endl;
        return (true);
    }
    else
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";p_amount:" << temp << ";withdrawal:refused"<< std::endl;
        return (false);
    }
}

void Account::_displayTimestamp(void)
{
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	std::time_t time_now = std::chrono::system_clock::to_time_t(now);

	tm time = *localtime(&time_now);
	std::cout << std::setfill('0') << "[" << (time.tm_year + 1900) << std::setw(2) << time.tm_mon + 1 << std::setw(2) << time.tm_mday << "_" << std::setw(2) << time.tm_hour << std::setw(2) << time.tm_min << std::setw(2) << time.tm_sec << "] ";
}
