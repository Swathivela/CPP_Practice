#include <iostream>
#include <iomanip>
using namespace std;

class SavingsAccount {
private:
    double savingsBalance; // individual balance
    static double annualInterestRate; // shared interest rate

public:
    // Constructor
    SavingsAccount(double balance = 0.0) {
        if (balance < 0.0)
            savingsBalance = 0.0;
        else
            savingsBalance = balance;
    }

    // Calculate monthly interest and update balance
    void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate) / 12;
        savingsBalance += monthlyInterest;
    }

    // Static function to modify the annual interest rate
    static void modifyInterestRate(double newRate) {
        annualInterestRate = newRate;
    }

    // Getter for balance
    double getBalance() const {
        return savingsBalance;
    }
};

// Initialize static member
double SavingsAccount::annualInterestRate = 0.0;

// Driver program
int main() {
    SavingsAccount saver1(2000.0);
    SavingsAccount saver2(3000.0);

    // Set interest rate to 3%
    SavingsAccount::modifyInterestRate(0.03);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << fixed << setprecision(2);
    cout << "After setting annual interest rate to 3%:" << endl;
    cout << "Saver1 balance: $" << saver1.getBalance() << endl;
    cout << "Saver2 balance: $" << saver2.getBalance() << endl;

    // Set interest rate to 4%
    SavingsAccount::modifyInterestRate(0.04);

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << "\nAfter setting annual interest rate to 4%:" << endl;
    cout << "Saver1 balance: $" << saver1.getBalance() << endl;
    cout << "Saver2 balance: $" << saver2.getBalance() << endl;

    return 0;
}
