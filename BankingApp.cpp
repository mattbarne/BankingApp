#include <iostream>
using namespace std;

#include "BankingApp.h"


BankingApp::BankingApp() {
    initialInvestment = 0;
    monthlyDeposit = 0;
    annualInterest = 0;
    numYears = 0;   
}

double BankingApp::getInitialInvestment() {
    return initialInvestment;
}

double BankingApp::getMonthlyDeposit(){
    return monthlyDeposit;
}

int BankingApp::getAnnualInterest(){
    return annualInterest;
}

int BankingApp::getNumYears(){
    return numYears;
}

void BankingApp::setInitialInvestment(double initialInvestment) {
    this->initialInvestment = initialInvestment;
}

void BankingApp::setMonthlyDeposit(double monthlyDeposit) {
    this->monthlyDeposit = monthlyDeposit;
}

void BankingApp::setAnnualInterest(int annualInterest) {
    this->annualInterest = annualInterest;
}

void BankingApp::setNumYears(int numYears) {
    this->numYears = numYears;
}