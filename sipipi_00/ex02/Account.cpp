#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {

  char buffer[80];
  std::time_t rawtime;
  std::time(&rawtime);
  std::tm *timeinfo = std::localtime(&rawtime);
  std::strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
  std::cout << buffer;
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
  // [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
  _displayTimestamp();
  std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";withdrawals:" << getNbWithdrawals() << "\n";
}

void Account::displayStatus() const {
  // [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";deposits:" << this->_nbDeposits
            << ";withdrawals:" << this->_nbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit) {
  // [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";deposit:" << deposit << ";amount:" << this->_amount + deposit
            << ";nb_deposits:" << ++(this->_nbDeposits) << "\n";
  this->_amount = this->_amount + deposit;
  _totalAmount += deposit;
  _totalNbDeposits++;
}

int Account::checkAmount() const { return this->_amount; }

bool Account::makeWithdrawal(int withdrawal) {

  if (this->_amount < withdrawal) {
    // [19920104_091532] index:0;p_amount:47;withdrawal:refused
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << this->_amount << ";withdrawal:refused" << "\n";
    return false;
  }
  // [19920104_091532]
  // index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
            << ";withdrawal:" << withdrawal
            << ";amount:" << this->_amount - withdrawal
            << ";nb_withdrawals:" << ++(this->_nbWithdrawals) << "\n";
  this->_amount = this->_amount - withdrawal;
  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  return true;
}

Account::Account() {}

Account::Account(int initial_deposit) {
  // [19920104_091532] index:0;amount:42;created
  _displayTimestamp();
  this->_accountIndex = _nbAccounts++;
  std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit
            << ";created" << "\n";
  this->_amount = initial_deposit;
  _totalAmount += initial_deposit;
  this->_nbDeposits = this->_nbWithdrawals = 0;
}

Account::~Account() {
  // [19920104_091532] index:0;amount:47;closed
  _displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
            << ";closed" << "\n";
}
