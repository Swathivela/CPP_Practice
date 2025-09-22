#include <iostream>
#include <iomanip>
using namespace std;

class ElectricBill {
private:
    double amountPaid;

public:
    // Constructor
    ElectricBill(double amount) {
        if (amount < 0) {
            amountPaid = 0;
        } else {
            amountPaid = amount;
        }
    }

    // Getter
    double getAmountPaid() const {
        return amountPaid;
    }

    // Setter
    void setAmountPaid(double amount) {
        if (amount < 0) {
            amountPaid = 0;
        } else {
            amountPaid = amount;
        }
    }

    // Deduction methods
    double getVAT() const {
        return amountPaid * 0.18; // 18%
    }

    double getREA() const {
        return amountPaid * 0.03; // 3%
    }

    double getEWURA() const {
        return amountPaid * 0.01; // 1%
    }

    // Calculate remaining amount for units
    double getRemaining() const {
        double serviceCharge = 5000.0;
        double remaining = amountPaid - (getVAT() + getREA() + getEWURA() + serviceCharge);
        if (remaining < 0) {
            return 0.0;
        }
        return remaining;
    }

    // Calculate units
    double getUnits() const {
        const double pricePerUnit = 295.0;
        return getRemaining() / pricePerUnit;
    }
};

// Driver program
int main() {
    double amount;
    cout << "Enter amount paid (in Tanzanian Shillings): ";
    cin >> amount;

    ElectricBill bill(amount);

    cout << fixed << setprecision(2);
    cout << "\n--- Electricity Bill Summary ---\n";
    cout << "Amount Paid: " << bill.getAmountPaid() << " Tsh" << endl;
    cout << "VAT (18%): " << bill.getVAT() << " Tsh" << endl;
    cout << "REA (3%): " << bill.getREA() << " Tsh" << endl;
    cout << "EWURA (1%): " << bill.getEWURA() << " Tsh" << endl;
    cout << "Service Charge: 5000.00 Tsh" << endl;
    cout << "Remaining Balance: " << bill.getRemaining() << " Tsh" << endl;
    cout << "Units Purchased: " << bill.getUnits() << " kWh" << endl;

    return 0;
}
