#include "Saving.h"
#include <iostream>


//    Saving(double balance, double annualInterestRate);
Saving::Saving(double balance, double annualInterestRate) : BankAccount(balance, annualInterestRate) {


    status =  getBalance() >= MIN_ACCOUNT_BALANCE;
}

bool Saving::checkStatus() {

    status = getBalance() >= MIN_ACCOUNT_BALANCE;

    return status;
}

void Saving::withdraw(double withdraw) {
    if (!checkStatus()) {
        //throw std::domain_error("Withdrawal denied. Account inactive due to insufficient balance.");

        std::cout<<"Withdrawal denied. Account inactive due to insufficient balance."<<std::endl;
    }
    BankAccount::withdraw(withdraw);
    checkStatus(); // Update status after withdrawal
}


void Saving::deposit(double deposit) {

    if (!checkStatus() && ((getBalance() + deposit) >= MIN_ACCOUNT_BALANCE)) {
        status = true;
    }


    BankAccount::deposit(deposit);

    checkStatus();
}

void Saving::monthlyProc() {
    if (getWithdrawNum() > WITHDRAW_LIMIT) {
        double serviceCharge = ((getWithdrawNum() - WITHDRAW_LIMIT) * SAVING_WITHDRAW_FEE);

        setMonthlyServiceCharge(serviceCharge);
    }

    BankAccount::monthlyProc();
    checkStatus();
}


std::string Saving::to_String() {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);

    out << "=========================================\n"
        << "            Saving Account Summary      \n"
        << "=========================================\n";

    // Printing each detail with fixed width for alignment
    out << std::left << std::setw(35) << "Current Balance:" << "$" << std::setw(10) << getBalance() << "\n"
        << std::setw(35) << "Account Status:" << std::setw(10) << (checkStatus() ? "Active" : "Inactive") << "\n"
        << std::setw(35) << "Monthly Service Charge:" << "$" << std::setw(10) << getMonthlyServiceCharge() << "\n"
        << std::setw(35) << "Total Withdrawals This Month:" << std::setw(10) << getWithdrawNum() << "\n"
        << std::setw(35) << "Annual Interest Rate:" << std::setw(10) << getAnnualInterestRate() << " %\n";

    out << "=========================================\n";

    return out.str();
}
