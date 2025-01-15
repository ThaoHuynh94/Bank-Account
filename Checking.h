
#ifndef CHECKING_H
#define CHECKING_H

#include "Bank.h"
#include <iostream>

// Global constants for overdraft limit and fee
const double CHECKING_OVERDRAFT_LIMIT = -500.0; ///< Maximum allowed overdraft for the checking account.
const double CHECKING_OVERDRAFT_FEE = 35.0;    ///< Fee charged for overdraft on the checking account.
const double CHECKING_MONTHLY_FEE = 5.0;       ///< Monthly fee for the checking account.
const double CHECKING_WITHDRAWAL_FEE = 0.10;   ///< Fee for each withdrawal (check written) from the checking account.

/**
 * @class Checking
 * @brief A class representing a checking bank account, derived from the BankAccount class.
 *
 * This class handles specific checking account functionalities, such as allowing withdrawals
 * that could cause a negative balance, enforcing an overdraft limit, applying monthly fees,
 * and managing the withdrawal fee for each check written. It also ensures that an overdraft fee
 * is charged when the account balance falls below zero.
 */
class Checking : public BankAccount {
public:
    /**
     * @brief Constructor that initializes the checking account with a specific balance and annual interest rate.
     *
     * @param balance The initial balance of the checking account.
     * @param annualInterestRate The annual interest rate for the checking account (in percentage).
     */
    Checking(double balance, double annualInterestRate);

    /**
     * @brief Withdraws a specified amount from the checking account.
     *
     * This function allows a withdrawal even if it causes the balance to become negative, but it ensures
     * that the balance does not go below the overdraft limit. If the withdrawal causes the balance to fall
     * below the overdraft limit, the withdrawal is not allowed.
     *
     * @param withdraw The amount to withdraw from the account.
     */
    virtual void withdraw(double withdraw) override;

    /**
     * @brief Processes the monthly operations for the checking account.
     *
     * This function adds the monthly service charge and checks whether an overdraft fee should be applied.
     * If the account balance is negative, an overdraft fee is charged. Calls the base class `monthlyProc`
     * to handle the standard monthly operations after applying any specific checking account charges.
     */
    virtual void monthlyProc() override;

    /**
     * @brief Converts the checking account information to a string representation.
     *
     * Returns a string summary of the account's current balance, overdraft limit, overdraft fee,
     * monthly service charge, and the number of withdrawals made in the current month.
     *
     * @return A string representation of the checking account.
     */
    std::string to_String() override;

};

#endif
