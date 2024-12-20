#ifndef SAVING_H
#define SAVING_H

#include "Bank.h"

/**
 * @class Saving
 * @brief A class representing a savings bank account, derived from the BankAccount class.
 *
 * This class provides functionalities specific to a savings account, including withdrawal and deposit conditions
 * based on account status, and monthly service charge handling based on the number of withdrawals.
 * The account becomes inactive if the balance falls below $25 and becomes active again when the balance is raised above $25.
 */
class Saving : public BankAccount {
private:
    bool status; ///< Account status (true for active, false for inactive). Inactive if balance falls below $25.

public:
    /**
     * @brief Constructor that initializes the savings account with a specific balance and annual interest rate.
     *
     * @param balance The initial balance of the account
     * @param annualInterestRate The annual interest rate for the account (in percentage)
     */
    Saving(double balance, double annualInterestRate);

    /**
     * @brief Withdraws a specified amount from the savings account.
     *
     * Checks if the account is active before allowing the withdrawal. If the account is inactive (balance below $25),
     * no withdrawal is allowed. Otherwise, calls the base class `withdraw` method to complete the transaction.
     *
     * @param withdraw The amount to withdraw
     */
    virtual void withdraw(double withdraw) override;

    /**
     * @brief Deposits a specified amount into the savings account.
     *
     * If the account is inactive (balance below $25), it checks if the deposit raises the balance above $25.
     * If so, the account is activated again. The deposit is then made by calling the base class `deposit` method.
     *
     * @param deposit The amount to deposit
     */
    virtual void deposit(double deposit) override;

    /**
     * @brief Processes the monthly operations for the savings account.
     *
     * This function checks if the number of withdrawals exceeds the monthly limit (4 withdrawals).
     * For each excess withdrawal, a $1 service charge is added to the monthly service charges.
     * If the balance falls below $25 after the service charge, the account becomes inactive.
     * Calls the base class `monthlyProc` to complete the processing after updating service charges.
     */
    virtual void monthlyProc() override;

    /**
     * @brief Checks the status of the savings account.
     *
     * This function checks if the account's balance is above the minimum threshold ($25)
     * and returns the current status (active or inactive).
     *
     * @return true if the account is active (balance >= $25), false otherwise
     */
    bool checkStatus();

    /**
     * @brief Converts the savings account information to a string representation.
     *
     * Returns a string summary of the account's current balance, status (active or inactive),
     * monthly service charge, total withdrawals, and annual interest rate.
     *
     * @return A string representation of the savings account
     */
    std::string to_String() override;

};

#endif
