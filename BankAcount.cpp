#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class BankAccount {
public:
    BankAccount(string name, int accountNumber, double initialDeposit)
        : accountHolderName(name), accountNumber(accountNumber), balance(initialDeposit) {}

    string getAccountHolderName() { return accountHolderName; }
    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << ". New balance is " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrew " << amount << ". New balance is " << balance << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

private:
    string accountHolderName;
    int accountNumber;
    double balance;
};

class BankingSystem {
public:
    void createAccount(string name, int accountNumber, double initialDeposit) {
        accounts.push_back(BankAccount(name, accountNumber, initialDeposit));
        cout << "Account created for " << name << " with account number " << accountNumber << endl;
    }

    void depositMoney(int accountNumber, double amount) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.deposit(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void withdrawMoney(int accountNumber, double amount) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.withdraw(amount);
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void checkBalance(int accountNumber) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                cout << "Balance for account number " << accountNumber << " is " << account.getBalance() << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void displayAllAccounts() {
        for (auto &account : accounts) {
            cout << "Account Holder: " << account.getAccountHolderName()
                 << ", Account Number: " << account.getAccountNumber()
                 << ", Balance: " << account.getBalance() << endl;
        }
    }

private:
    vector<BankAccount> accounts;
};

int main() {
    BankingSystem bankingSystem;
    int choice, accountNumber;
    string name;
    double amount;

    do {
        cout << "\n--- Banking System Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account holder's name: ";
                cin >> name;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter initial deposit amount: ";
                cin >> amount;
                bankingSystem.createAccount(name, accountNumber, amount);
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: ";
                cin >> amount;
                bankingSystem.depositMoney(accountNumber, amount);
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                bankingSystem.withdrawMoney(accountNumber, amount);
                break;
            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                bankingSystem.checkBalance(accountNumber);
                break;
            case 5:
                bankingSystem.displayAllAccounts();
                break;
            case 0:
                cout << "Exiting system." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
