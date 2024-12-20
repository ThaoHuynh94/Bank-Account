#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// Constants for account limits and fees
const double MIN_ACCOUNT_BALANCE = 25.00;   ///< Minimum balance required for saving account status
const int    WITHDRAW_LIMIT = 4;         ///< Withdrawal limit per month
const double SAVING_WITHDRAW_FEE = 1.0; // Withdrawal fee for savings account
const double ZERO_BALANCE = 0.0;        ///< Used to represent a zero balance.

/**
 * @class BankAccount
 * @brief A class representing a general bank account with basic functionalities like deposit, withdrawal, interest calculation, and monthly processing.
 *
 * This class serves as a base class for accounts like Saving and Checking, providing virtual functions to be overridden in derived classes. It supports operations such as depositing money, withdrawing money, calculating interest, and processing monthly fees.
 */
class BankAccount {
private:
    double balance;                 ///< Current balance in the bank account
    int depositNum;                 ///< Number of deposits made this month
    int withdrawalNum;              ///< Number of withdrawals made this month
    double annualInterestRate;      ///< Annual interest rate (in percentage)
    double monthlyServiceCharges;   ///< Monthly service charges applied to the account

public:
    /**
     * @brief Default constructor that initializes the bank account with default values.
     *
     * Initializes balance to 0, deposit and withdrawal counts to 0, and interest rate and service charges to 0.
     */
    BankAccount();

    /**
     * @brief Constructor that initializes a bank account with a specific balance and annual interest rate.
     *
     * This constructor initializes the bank account with the given balance and annual interest rate,
     * ensuring that the balance is non-negative. It also sets the initial values for the number of deposits,
     * withdrawals, and monthly service charges to zero.
     *
     * @param balance The initial balance of the account (must be non-negative).
     * @param annualInterestRate The annual interest rate for the account (in percentage, e.g., 5 for 5%).
     * @throws std::domain_error if the balance is less than $25, as accounts cannot be activated with less than a minimum balance.
     */
    BankAccount(double balance, double annualInterestRate);

    /**
     * @brief Deposits a specified amount into the bank account.
     *
     * Adds the deposit amount to the account balance and increments the deposit counter.
     *
     * @param deposit The amount to deposit
     */
    virtual void deposit(double deposit);

    /**
     * @brief Withdraws a specified amount from the bank account.
     *
     * Subtracts the withdrawal amount from the account balance and increments the withdrawal counter.
     *
     * @param withdraw The amount to withdraw
     */
    virtual void withdraw(double withdraw);

    /**
     * @brief Calculates the monthly interest based on the annual interest rate.
     *
     * Adds the calculated interest to the account balance.
     */
    virtual void calcInt();

    /**
     * @brief Processes the account at the end of the month.
     *
     * Subtracts the monthly service charges from the balance, calls calcInt to calculate and add interest,
     * and resets the deposit, withdrawal counters, and service charges for the next month.
     */
    virtual void monthlyProc();

    /**
     * @brief Gets the current balance of the bank account.
     *
     * @return The current balance
     */
    double getBalance() const;

    /**
     * @brief Gets the total number of withdrawals made this month.
     *
     * @return The number of withdrawals
     */
    int getWithdrawNum() const;

    /**
     * @brief Sets the monthly service charge for the bank account.
     *
     * @param serviceCharge The service charge amount to set
     */
    void setMonthlyServiceCharge(double serviceCharge);

    /**
     * @brief Gets the current monthly service charge for the bank account.
     *
     * @return The monthly service charge
     */
    double getMonthlyServiceCharge() const;

    /**
     * @brief Gets the annual interest rate for the bank account.
     *
     * @return The annual interest rate in percentage
     */
    int getAnnualInterestRate() const;

    /**
     * @brief Converts the bank account information to a string representation.
     *
     * This function returns a string summary of the account's current balance,
     * monthly service charges, number of deposits and withdrawals, and annual interest rate.
     *
     * @return A string representation of the bank account
     */
    virtual std::string to_String();  // Adding to_String here
};

#endif
