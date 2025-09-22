#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    string name;
    double balance;

public:
    // Constructor
    Account(string accountName, double initialBalance) {
        name = accountName;
        if (initialBalance > 0.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
        }
    }

    // Deposit
    void deposit(double depositAmount) {
        if (depositAmount > 0.0) {
            balance = balance + depositAmount;
        }
    }

    // Getter for balance
    double getBalance() const {
        return balance;
    }

    // Setter and Getter for name
    void setName(string accountName) {
        name = accountName;
    }

    string getName() const {
        return name;
    }
};

// ---------------- New Function ----------------
void displayAccount(Account accountToDisplay) {
    cout << accountToDisplay.getName() 
         << " balance: $" << accountToDisplay.getBalance() << endl;
}
// ------------------------------------------------

int main() {
    Account account1("Jane Green", 50.0);
    Account account2("John Blue", -7.0);

    // Display balances using displayAccount (no duplicate code now)
    displayAccount(account1);
    displayAccount(account2);

    cout << "\nEnter deposit amount for account1: ";
    double depositAmount;
    cin >> depositAmount;
    cout << "adding " << depositAmount << " to account1 balance\n\n";
    account1.deposit(depositAmount);

    // Again using displayAccount
    displayAccount(account1);
    displayAccount(account2);

    cout << "\nEnter deposit amount for account2: ";
    cin >> depositAmount;
    cout << "adding " << depositAmount << " to account2 balance\n\n";
    account2.deposit(depositAmount);

    // Again using displayAccount
    displayAccount(account1);
    displayAccount(account2);

    return 0;
}
