#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Structure to store transaction details
struct Transaction {
    string type;
    double amount;
};

class Account {
private:
    string username;
    int pin;
    double balance;
    vector<Transaction> transactionHistory;

public:
    Account(string uname, int upin = -1, double initialBalance = 0.0)
        : username(uname), pin(upin), balance(initialBalance) {}

    // Generate new PIN using OTP
    void generatePin() {
        string phoneNumber;
        cout << "Enter your registered phone number: ";
        cin >> phoneNumber;

        // Generate OTP
        srand(time(0));
        int otp = 1000 + (rand() % 9000);
        cout << "OTP sent to " << phoneNumber << ": " << otp << " (Simulated)\n";

        int enteredOtp;
        cout << "Enter the OTP: ";
        cin >> enteredOtp;

        if (enteredOtp == otp) {
            cout << "OTP verified. Enter your new 4-digit PIN: ";
            cin >> pin;
            cout << "PIN successfully generated!\n";
        } else {
            cout << "Invalid OTP. PIN generation failed.\n";
        }
    }

    // Authenticate user
    bool authenticate(int inputPin) {
        return inputPin == pin;
    }

    // Display current balance
    void displayBalance() {
        cout << "Current balance: ₹" << balance << endl;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back({"Deposit", amount});
            cout << "Successfully deposited ₹" << amount << "." << endl;
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                transactionHistory.push_back({"Withdrawal", amount});
                cout << "Successfully withdrew ₹" << amount << "." << endl;
            } else {
                cout << "Insufficient funds. Transaction failed." << endl;
            }
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }

    // Show transaction history
    void showTransactionHistory() {
        if (transactionHistory.empty()) {
            cout << "No transactions available." << endl;
        } else {
            cout << "\nTransaction History:" << endl;
            for (const auto& transaction : transactionHistory) {
                cout << transaction.type << ": ₹" << transaction.amount << endl;
            }
        }
    }

    // Check if PIN is generated
    bool isPinGenerated() const {
        return pin != -1;
    }
};

int main() {
    // Create an account for a new user with no PIN
    Account userAccount("New User");

    cout << "=== Welcome to the ATM Management System ===" << endl;

    if (!userAccount.isPinGenerated()) {
        cout << "You don't have a PIN. Please generate a new PIN first." << endl;
        userAccount.generatePin();
        if (!userAccount.isPinGenerated()) {
            cout << "Unable to proceed without a PIN. Exiting...\n";
            return 0;
        }
    }

    // Authenticate user
    int inputPin;
    cout << "Enter your PIN: ";
    cin >> inputPin;

    if (!userAccount.authenticate(inputPin)) {
        cout << "Incorrect PIN. Access denied." << endl;
        return 0;
    }

    int choice;
    do {
        // Display Menu
        cout << "\n=== ATM Menu ===" << endl;
        cout << "1. Balance Inquiry" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. View Transaction History" << endl;
        cout << "5. Generate New PIN" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Balance Inquiry
                userAccount.displayBalance();
                break;
            case 2: { // Deposit Money
                double amount;
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                userAccount.deposit(amount);
                break;
            }
            case 3: { // Withdraw Money
                double amount;
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                userAccount.withdraw(amount);
                break;
            }
            case 4: // View Transaction History
                userAccount.showTransactionHistory();
                break;
            case 5: // Generate New PIN
                userAccount.generatePin();
                break;
            case 6: // Exit
                cout << "Thank you for using the ATM. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

