#include <iostream>
#include <iomanip>
using namespace std;
#include "BankingApp.h"

// Function prints the needed data after every call in the loop
void printData(int currentYear, double yearEndBalance, double yearlyInterest, string title){
    cout << fixed << setprecision(2);
    
    cout << "\n" << title << endl;
    cout << "\n|---------------------------|\n";
    cout << "\nBalance for year " << currentYear << ": ";
    cout << "\nYear End Balance: " << yearEndBalance;
    cout << "\nYear End Earned Interest: " << yearlyInterest;

    cout << "\n";
}

// Calculates yearly gross with no monthly payment
int balanceNoMonthlyDeposit(double investment,int annualInterestRate, int years){
    double yearlyInvestment = investment;
    double yearlyInterestRate = annualInterestRate / 100.0;
    int currentYear = 1;

    for(int i = 0; i < years; i++){
        double yearlyInterest = yearlyInvestment * yearlyInterestRate;
        double yearEndBalance = yearlyInvestment + yearlyInterest;

        printData(currentYear, yearEndBalance, yearlyInterest, "Balance and Interest Without Additional Monthly Deposits");

        yearlyInvestment = yearEndBalance;
        currentYear++;
    }

    return 0;
}

// Calculates yearly gross with monthly payments added
int balanceWithMonthlyDeposit(double investment, double monthlyDeposit, int annualInterestRate, int years){
    double yearlyInvestment = investment;
    double monthlyInterestRate = annualInterestRate / 100.0 / 12.0;
    int currentYear = 1;

        for(int i = 0; i < years; i++){
            double yearlyInterest = 0.0;
            double yearEndBalance = yearlyInvestment;

        for(int j = 0; j < 12; j++){
            yearEndBalance += monthlyDeposit;
            double monthlyInterest = yearEndBalance * monthlyInterestRate;
            yearlyInterest += monthlyInterest;
            yearEndBalance += monthlyInterest;
        }

        printData(currentYear, yearEndBalance, yearlyInterest, "Balance and Interest With Additional Monthly Deposits");

        yearlyInvestment = yearEndBalance;
        currentYear++;
    }

    return 0;
}

int main(){
    // Declare variables
    BankingApp report1;

    char choice;

    double investment;
    double deposit;
    int interest;
    int years;

    // Prompt for initial questions
    cout << "Initial Investment Amount: ";
    cin >> investment;
    report1.setInitialInvestment(investment);

    cout << "Monthly Deposit: ";
    cin >> deposit;
    report1.setMonthlyDeposit(deposit);

    cout << "Annual Interest: ";
    cin >> interest;
    report1.setAnnualInterest(interest);

    cout << "Number of years: ";
    cin >> years;
    report1.setNumYears(years);

    // Display questions and how the response
    cout << "\nInitial Investment Amount: ";
    cout << fixed << setprecision(2) << '$' << report1.getInitialInvestment() << endl;

    cout << "Monthly Deposit: ";
    cout << fixed << setprecision(2) << '$' << report1.getMonthlyDeposit() << endl;

    cout << "Annual Interest: ";
    cout << report1.getAnnualInterest() << '%' << endl;

    cout << "Number of years: ";
    cout << report1.getNumYears() << endl;

    cout << "\nPress any key to view data or 'q' to quit...";

    // Clear the input before cin.get
    cin.ignore();
    choice = cin.get();

    // Checks if the user wants to quit or continue
    if(choice == 'q' || choice == 'Q'){
        cout << "quitting..";
        return 0;
    }

    cout << "\nLoading data...\n";
    
    // Call functions to display data
    balanceNoMonthlyDeposit(report1.getInitialInvestment(), report1.getAnnualInterest(), report1.getNumYears());
    balanceWithMonthlyDeposit(report1.getInitialInvestment(), report1.getMonthlyDeposit(), report1.getAnnualInterest(), report1.getNumYears());

    return 0;
}