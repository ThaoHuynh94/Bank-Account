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


// Implementing to_String for Saving class
std::string Saving::to_String()  {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);

    out << "Saving Account Summary:\n"
        << "-----------------------------------\n"
        << "Current Balance: $" << getBalance() << "\n"
        << "Account Status: " << (checkStatus() ? "Active" : "Inactive") << "\n"
        << "Monthly Service Charge: $" << getMonthlyServiceCharge() << "\n"
        << "Total Withdrawals This Month: " << getWithdrawNum() << "\n"
        << "Annual Interest Rate: " << getAnnualInterestRate() << "%\n"
        << "-----------------------------------\n";

    return out.str();
}
