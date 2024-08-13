#ifndef BANKING_APP_H
#define BANKING_APP_H
#include <string>
using namespace std;

class BankingApp {
    private:
    double initialInvestment;
    double monthlyDeposit;
    int annualInterest;
    int numYears;

    public:
    BankingApp();
      
    double getInitialInvestment();
    double getMonthlyDeposit();
    int getAnnualInterest();
    int getNumYears();

    void setInitialInvestment(double initialInvestment);
    void setMonthlyDeposit(double monthlyDeposit);
    void setAnnualInterest(int annualInterest);
    void setNumYears(int numYears);
};

#endif