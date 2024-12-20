#include "Saving.h"
#include "Bank.h"
#include "Checking.h"
#include <iostream>
#include <iomanip>
#include <iostream>


void userData(BankAccount *pointer) {
    double depositAmount, withdrawalsAmount;
    int depositTimes, withdrawalTimes, userchoice;
    int repeatChoice;

    do {
        // Show initial balance
        std::cout << "Beginning balance of this month: $" << pointer->getBalance() << std::endl << std::endl;
        std::cout << "For this month:" << std::endl;
        std::cout << "1. Deposit." << std::endl;
        std::cout << "2. Withdrawals." << std::endl;
        std::cout << "3. Exit." << std::endl;  // Option to exit the loop

        // Get user input for deposit or withdrawal
        while (!(std::cin >> userchoice) || userchoice < 1 || userchoice > 3) {
            std::cout << "Enter your choice again (1, 2, or 3): ";
        }

        switch (userchoice) {
            case 1: { // Deposit Case
                std::cout << "Enter times for deposit: ";
                while (!(std::cin >> depositTimes) || depositTimes < 0) {
                    std::cout << "Reenter times for deposit: ";
                }
                for (int i = 0; i < depositTimes; i++) {
                    std::cout << "Enter the amount of deposit: ";
                    while ((!(std::cin >> depositAmount) || depositAmount < 0)) {
                        std::cout << "Please reenter the amount of deposit: ";
                    }
                    pointer->deposit(depositAmount);
                }
                std::cout << "Monthly service charge: $" << std::setprecision(2) << std::fixed << pointer->getMonthlyServiceCharge() << std::endl;
                pointer->monthlyProc(); // Apply monthly processing
                std::cout << "Deposit number: " << depositTimes << std::endl;
                std::cout << "Ending balance: $" << pointer->getBalance() << std::endl;
            } break;

            case 2: { // Withdrawals Case
                std::cout << "Enter times for withdrawals: ";
                while (!(std::cin >> withdrawalTimes) || withdrawalTimes < 0) {
                    std::cout << "Reenter times for withdrawals: ";
                }
                for (int i = 0; i < withdrawalTimes; i++) {
                    std::cout << "Enter the amount of withdrawal: ";
                    while ((!(std::cin >> withdrawalsAmount) || withdrawalsAmount < 0)) {
                        std::cout << "Please reenter the amount of withdrawal: ";
                    }
                    pointer->withdraw(withdrawalsAmount);
                }
                std::cout << "Monthly service charge: $" << std::setprecision(2) << std::fixed << pointer->getMonthlyServiceCharge() << std::endl;
                pointer->monthlyProc(); // Apply monthly processing
                std::cout << "Withdrawal number: " << withdrawalTimes << std::endl;
                std::cout << "Ending balance: $" << pointer->getBalance() << std::endl;
            } break;

            case 3: { // Exit Case
                std::cout << "Exiting the operation." << std::endl;
                break;
            }

            default:
                std::cout << "Invalid option selected!" << std::endl;
                break;
        }

        // Ask user if they want to continue with another operation
        if (userchoice != 3) {
            std::cout << "\nDo you want to perform another operation? (1 for Yes, 2 for No): ";
            while (!(std::cin >> repeatChoice) || (repeatChoice != 1 && repeatChoice != 2)) {
                std::cout << "Invalid input. Enter 1 to continue or 2 to exit: ";
            }
        } else {
            repeatChoice = 2; // Exit if the user selects '3' to exit
        }

    } while (repeatChoice == 1); // Repeat until the user chooses '2' to stop

    // Call the to_String method to display account details
    std::cout << "\nAccount details: " << std::endl;
    std::cout << pointer->to_String() << std::endl;
}


void createAccount() {
    int accountChoice;
    double initialBalance, annualInterestRate;

    std::cout << "Choose the type of bank account:" << std::endl;
    std::cout << "1. Regular Bank Account" << std::endl;
    std::cout << "2. Saving Account" << std::endl;
    std::cout << "3. Checking Account" << std::endl;

    while (!(std::cin >> accountChoice) || accountChoice < 1 || accountChoice > 3) {
        std::cout << "Invalid input. Please enter 1, 2, or 3: ";
    }

    std::cout << "Enter initial balance: $";
    while (!(std::cin >> initialBalance) || initialBalance < MIN_ACCOUNT_BALANCE) {
        std::cout << "Please enter a valid initial balance: $";
    }

    std::cout << "Enter annual interest rate (in percentage, e.g., 5.6 for 5.6%): ";
    while (!(std::cin >> annualInterestRate) || annualInterestRate < 0) {
        std::cout << "Please enter a valid annual interest rate: ";
    }

    BankAccount *account = nullptr;

    switch (accountChoice) {
        case 1: { // Regular Bank Account
            try{account = new BankAccount(initialBalance, annualInterestRate);}
            catch (std::logic_error &error){
                std::cout<<error.what()<<std::endl;
            }
            break;
        }
        case 2: { // Saving Account
            try {account = new Saving(initialBalance, annualInterestRate);}
            catch (std::logic_error &error){
                std::cout<<error.what()<<std::endl;
            }
            break;
        }
        case 3: { // Checking Account
            try{account = new Checking(initialBalance, annualInterestRate);}
            catch (std::logic_error &error){
                std::cout<<error.what()<<std::endl;
            }
            break;
        }
        default:
            std::cout << "Invalid choice." << std::endl;
            return;
    }

    userData(account);

    // Deallocate memory after use
    delete account;
}

int main() {
    createAccount();
    return 0;
}
