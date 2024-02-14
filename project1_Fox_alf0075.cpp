/* COMP 2710 project1FinalCode.cpp
* Avery Fox alf0075
* I refered to the project 1 hints given by Dr. Li and used the stucture and a skelton to build my code.
* FINAL!
*/
#include <iostream>
using namespace std;
int main() {
// VARIABLE INITIALIZATION

    double loanAmount;
    double interestAmount;
    double initialPayment;
    double monthlyInterestRate;
    double totalInterest;
    double principal;
    double interestRate;
    double interestRateCalc;

    int monthIterator;

// CURRENCY FORMATTING

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

// User Input
// function 'cout' will ask loan amount? to terminal and 'cin' will set user input as variable loanAmount
cout << "\nLoan Amount: ";
cin >> loanAmount;

// function 'cout' will ask interest rate? to terminal and 'cin' will set user input as variable loanAmount

cout << "Interest Rate (% per year): ";
cin >> interestRate;

// below code will get the correct interest rate calculations

monthlyInterestRate = interestRate / 12;
interestAmount = monthlyInterestRate * loanAmount / 100;
cout << "Monthly Payments: ";
cin >> initialPayment;

cout << endl;

// below code formats the Amortization Table 
// format is recieved for Dr. Li's hints

cout << "*****************************************************************\n"
<< "\tAmortization Table\n"
<< "*****************************************************************\n"
<< "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

// numbers below are for formatting the table headings
// imputted the numbers and changed to fit example

printf("%-6d $%-10.4lf %-9s %-3s %-10s %-4s\n", monthIterator, loanAmount,"N/A","N/A","N/A","N/A" );

// loop to fill table 

while (loanAmount > 0) {
        monthIterator++;
        interestAmount = monthlyInterestRate * loanAmount /100;
        totalInterest += interestAmount;
        principal = initialPayment - interestAmount;
        if (loanAmount < principal) {
            initialPayment = loanAmount + interestAmount;
            principal = loanAmount;
        }
        loanAmount -= principal;

        // numbers below are for formatting the table headings
        // imputted the numbers and changed to fit example

        printf("%-6d $%-9.4lf $%-8.2lf %-4.2lf $%-9.2lf $%-4.2lf\n", monthIterator, loanAmount, initialPayment, monthlyInterestRate, interestAmount, principal);
}

// final part of farmatting recieved from Dr. Li
// prints closing statements to terminal

cout << "****************************************************************\n";
cout << "\nIt takes " << monthIterator << " months to pay off "
<< "the loan.\n"
<< "Total interest paid is: $" << totalInterest;
cout << endl << endl;
return 0;

// Warning messages 

    if (loanAmount < 0) {
    cout << "Invalid loan" << endl;
    return 0;
    }

    
    
}