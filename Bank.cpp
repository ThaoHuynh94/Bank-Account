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
    depositAmount+= deposit;
}

void BankAccount::withdraw(double withdraw) {

    if(getBalance() - withdraw < ZERO_BALANCE)
    {
        std::cout<<"Withdrawal denied. Account inactive due to insufficient balance."<<std::endl;

    } else{
        balance -= withdraw;
        withdrawalNum++;
        withdrawAmount += withdraw;
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

    out << "=========================================\n"
        << "            Bank Account Summary        \n"
        << "=========================================\n"
        << std::left << std::setw(35) << "Current Balance:" << "$" << std::setw(12) << balance << "\n"
        << std::setw(35) << "Monthly Service Charge:" << "$" << std::setw(12) << monthlyServiceCharges << "\n"
        << std::setw(35) << "Total Deposit Amount This Month:" << "$" << std::setw(12) << depositAmount << "\n"
        << std::setw(35) << "Total Deposit Number This Month:" << std::setw(12) << depositNum << "\n"
        << std::setw(35) << "Total Withdrawal Number This Month:" << std::setw(12) << withdrawalNum << "\n"
        << std::setw(35) << "Total Withdrawal Amount This Month:" << "$" << std::setw(12) << withdrawAmount << "\n";
    out << std::setw(35) << "Annual Interest Rate:" << std::setw(10) << annualInterestRate << " %\n";

    out << "=========================================\n";

    return out.str();
}




int  BankAccount::getAnnualInterestRate() const{
    return  annualInterestRate;
}

