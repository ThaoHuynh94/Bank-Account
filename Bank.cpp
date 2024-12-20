#include "Bank.h"


BankAccount::BankAccount() : balance(0.0), depositNum(0), withdrawalNum(0), annualInterestRate(0.0), monthlyServiceCharges(0.0){}

BankAccount::BankAccount(double balance, double annualInterestRate) : annualInterestRate(annualInterestRate), depositNum(0),
withdrawalNum(0), monthlyServiceCharges(0.0) {

    //double check if the starting balance of the account is a valid amount

    if (balance < MIN_ACCOUNT_BALANCE )
    {
        throw std::domain_error("We only can activate an account with greater than $25 balance!");

    }
    this->balance = balance;
}


void BankAccount::deposit(double deposit) {
    balance += deposit;
    depositNum++;
}

void BankAccount::withdraw(double withdraw) {

    if(getBalance() - withdraw < ZERO_BALANCE)
    {
        std::cout<<"Withdrawal denied. Account inactive due to insufficient balance."<<std::endl;

    } else{
        balance -= withdraw;
        withdrawalNum++;
    }

}

void BankAccount::calcInt() {
    double monthlyInterestRate = (annualInterestRate / 12) / 100; // Convert annual rate to monthly decimal rate
    double monthlyInterest = balance * monthlyInterestRate; // Calculate the interest based on balance

    balance += monthlyInterest; // Add interest to the balance
}



void BankAccount::monthlyProc() {
    balance -= monthlyServiceCharges;
    calcInt();
    withdrawalNum = depositNum = 0;
    monthlyServiceCharges = 0.0;
}


int BankAccount::getWithdrawNum() const {
    return withdrawalNum;
}



void BankAccount::setMonthlyServiceCharge(double serviceCharge) {
    monthlyServiceCharges += serviceCharge;
}




double BankAccount::getBalance() const {
    return balance;
}



double BankAccount::getMonthlyServiceCharge() const{

    return monthlyServiceCharges;
}

std::string BankAccount::to_String() {
    std::ostringstream out;
    out << std::fixed << std::setprecision(2);

    out << "Bank Account Summary:\n"
        << "-----------------------------------\n"
        << "Current Balance: $" << balance << "\n"
        << "Monthly Service Charge: $" << monthlyServiceCharges << "\n"
        << "Total Deposits This Month: " << depositNum << "\n"
        << "Total Withdrawals This Month: " << withdrawalNum << "\n"
        << "Annual Interest Rate: " << annualInterestRate << "%\n"
        << "-----------------------------------\n";

    return out.str();
}


int  BankAccount::getAnnualInterestRate() const{
    return  annualInterestRate;
}

