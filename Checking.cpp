
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

    // Header with proper alignment
    out << "=========================================\n"
        << "          Checking Account Summary      \n"
        << "=========================================\n";

    // Printing each detail with fixed width for alignment
    out << std::left << std::setw(35) << "Current Balance:" << "$" << std::setw(10) << getBalance() << "\n"
        << std::setw(35) << "Overdraft Limit:" << "$" << std::setw(10) << CHECKING_OVERDRAFT_LIMIT << "\n"
        << std::setw(35) << "Overdraft Fee:" << "$" << std::setw(10) << CHECKING_OVERDRAFT_FEE << "\n"
        << std::setw(35) << "Monthly Service Charge:" << "$" << std::setw(10) << getMonthlyServiceCharge() << "\n"
        << std::setw(35) << "Total Withdrawals This Month:" << std::setw(10) << getWithdrawNum() << "\n";

    out << "=========================================\n";

    return out.str();
}

