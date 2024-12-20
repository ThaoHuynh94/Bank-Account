#include "checking.h"

// Constructor
Checking::Checking(double balance, double annualInterestRate)
        : BankAccount(balance, annualInterestRate) {}

void Checking::withdraw(double withdraw) {
    double newBalance = getBalance() - withdraw;

    if (newBalance < CHECKING_OVERDRAFT_LIMIT) {
        //throw std::domain_error("Withdrawal denied. Overdraft limit exceeded.");

        std::cout<<"Withdrawal denied. Account inactive due to insufficient balance."<<std::endl;
    } else {
        BankAccount::withdraw(withdraw);
    }
}

void Checking::monthlyProc() {


    // Apply overdraft fee if the balance is negative
    if (getBalance() < ZERO_BALANCE) {
        setMonthlyServiceCharge(getMonthlyServiceCharge() + CHECKING_OVERDRAFT_FEE);
    }

    // Apply standard service charges
    setMonthlyServiceCharge(CHECKING_MONTHLY_FEE + (CHECKING_WITHDRAWAL_FEE * getWithdrawNum()));


    BankAccount::monthlyProc();
}


std::string Checking::to_String() {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);

    out << "Checking Account Summary:\n"
        << "-----------------------------------\n"
        << "Current Balance: $" << getBalance() << "\n"
        << "Overdraft Limit: $" << CHECKING_OVERDRAFT_LIMIT << "\n"
        << "Overdraft Fee: $" << CHECKING_OVERDRAFT_FEE << "\n"
        << "Monthly Service Charge: $" << getMonthlyServiceCharge() << "\n"
        << "Total Withdrawals This Month: " << getWithdrawNum() << "\n"
        << "-----------------------------------\n";

    return out.str();
}