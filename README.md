
# Bank Account Management System

## Overview
The Bank Account Management System allows users to manage different types of bank accounts (Regular, Savings, and Checking). Users can perform deposits, withdrawals, and calculate monthly interest and service charges. It also handles overdraft limits and fees for checking accounts.

## Features
- **Account Types**: Support for Regular, Savings, and Checking accounts.
- **Deposits and Withdrawals**: Users can deposit or withdraw money, with account balance updates.
- **Interest Calculation**: Monthly interest is calculated for savings and regular accounts based on the annual interest rate.
- **Service Charges**: Monthly service charges are applied to accounts as needed.
- **Overdraft Management**: Special handling of overdraft limits and fees for Checking accounts.
- **Account Summary**: Provides a detailed summary of account activities, including balances, service charges, deposits, withdrawals, and annual interest rates.

## UML Diagram
Here is the UML diagram for the Bank Account:
<img width="1032" alt="Untitled P1 2" src="https://github.com/user-attachments/assets/548baab8-7e77-4cb8-a28e-5f5ef9220ff2" />


## Technologies Used
- **C++**: Object-oriented programming (OOP) with classes, inheritance, and polymorphism.
- **Standard Library**: Input/Output, exception handling, and utility functions.

## Sample Output

### Bank Account Summary

```
=========================================
            Bank Account Summary        
=========================================
Current Balance:                   $2745.16     
Monthly Service Charge:            $0.00        
Total Deposit Amount This Month:   $2000.00     
Total Deposit Number This Month:   2           
Total Withdrawal Number This Month:2           
Total Withdrawal Amount This Month:$300.00      
Annual Interest Rate:              7.00%
=========================================
```

### Saving Account Summary
```
=========================================
            Saving Account Summary      
=========================================
Current Balance:                   $2033.47   
Account Status:                    Active    
Monthly Service Charge:            $0.00      
Total Withdrawals This Month:      1         
Annual Interest Rate:              8%
=========================================

```
### Checking Account Summary
```
=========================================
          Checking Account Summary      
=========================================
Current Balance:                   $10437.55  
Overdraft Limit:                   $-500.00   
Overdraft Fee:                     $35.00     
Monthly Service Charge:            $10.20     
Total Withdrawals This Month:      2         
=========================================
```
