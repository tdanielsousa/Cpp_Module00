#include <ctime>
#include <iostream>
#include "Account.hpp"

///////////////////////////////////////////////////////////////////////////
// Static member init
// Global tracking counters shared across all
///////////////////////////////////////////////////////////////////////////
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

///////////////////////////////////////////////////////////////////////////
// Getters
///////////////////////////////////////////////////////////////////////////
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

///////////////////////////////////////////////////////////////////////////
// Constructor and destructor
// Account init and destruction with logging
///////////////////////////////////////////////////////////////////////////

// Initializes account index, initial balance, and zeroes deposit/withdrawal counts
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created\n";
}

// Logs account closure when object goes out of scopee
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed\n";
}

///////////////////////////////////////////////////////////////////////////
// Account operations
// Member methods for balance check, deposits, and withdrawals
///////////////////////////////////////////////////////////////////////////
int Account::checkAmount(void) const
{
    return _amount;
}

// Adds funds to the account and updates global bank totals
void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "deposit:" << deposit << ";";

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << "\n";
}

// Try withdrawal, refuses transaction if funds are not enough
bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";";

    if (_amount < withdrawal)
    {
        std::cout << "withdrawal:refused\n";
        return false;
    }

    std::cout << "withdrawal:" << withdrawal << ";";

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals << "\n";
    return true;
}

///////////////////////////////////////////////////////////////////////////
// Display and logging
// Outputs formatted sys info to stdout
///////////////////////////////////////////////////////////////////////////

// Prints combined bank information across all accounts
void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals << "\n";
}

// Prints the current state of a specific account instance
void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << "\n";
}

// Prints standard timestamp header in [YYYYMMDD_HHMMSS] format
void Account::_displayTimestamp(void)
{
    time_t current = time(NULL);
    struct tm* local = localtime(&current);

    char buffer[20];

    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", local);

    std::cout << buffer;
}
