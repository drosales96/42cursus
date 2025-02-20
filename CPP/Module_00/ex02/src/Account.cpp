/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drosales <drosales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:30:04 by drosales          #+#    #+#             */
/*   Updated: 2025/02/19 12:30:05 by drosales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Account.hpp"

// Initialation of static members

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor

Account::Account (int initial_deposit){
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount << ";created" \
    << std::endl;
}

// Deconstructor

Account::~Account (void) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
    << ";amount:" << this->_amount << ";closed" \
    << std::endl;
}

// Methods that gets the information from the class

int Account::getNbWithdrawals (void) {
    return (Account::_totalNbWithdrawals);
}

int Account::getNbDeposits (void) {
    return (Account::_totalNbDeposits);
}

int Account::getTotalAmount (void) {
    return (Account::_totalAmount);
}

int Account::getNbAccounts (void) {
    return (Account::_nbAccounts);
}

// This method displays information after movements

void    Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() \
    << ";total:" << Account::getTotalAmount() << ";deposits:" \
    << Account::getNbDeposits() << ";withdrawals:" \
    << Account::getNbWithdrawals() << std::endl;
}

// This method registers the data of a deposit

void    Account::makeDeposit (int deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
    << ";p_amount:" << this->_amount;
    this->_amount += deposit;
    this->_nbDeposits += 1;
    _totalAmount += deposit; 
    _totalNbDeposits += 1;
    std::cout << ";deposit:" << deposit << ";amount:" \
    << this->_amount << ";nb_deposits:" << this->_nbDeposits \
    << std::endl;
}

 /* This method checks if the amount is negative or not , it will be use
 when a withdrawal is happening */

int Account::checkAmount(void) const {
    if (this->_amount < 0)
        return (1);
    return (0);
}

// This method registers the data of a withdrawal ("Retiro de dinero")
// The method returns bool 0 when is refused and 1 when it is done

bool    Account::makeWithdrawal (int withdrawal)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex \
    << ";p_amount:" << this->_amount;
    this->_amount -= withdrawal;
    if (checkAmount() == 1)
    {
        this->_amount += withdrawal;
        std::cout << ";withdrawal:refused" << std::endl;
        return (0);
    }
    _totalAmount -= withdrawal;
    _nbWithdrawals += 1;
    _totalNbWithdrawals += 1;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" \
    << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals \
    << std::endl;
    return (1);
}

void    Account::displayStatus (void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" \
    << this->_amount << ";deposits:" << this->_nbDeposits \
    << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t timing;

    timing = time(NULL);
    struct tm *tm_info = localtime(&timing);
    char buff[20];
    strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S] ", tm_info);
    std::cout << buff;
}
