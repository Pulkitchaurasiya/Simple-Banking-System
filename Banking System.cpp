#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ---------------- TRANSACTION CLASS ----------------
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void display() {
        cout << type << " : " << amount << endl;
    }
};

// ---------------- ACCOUNT CLASS ----------------
class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo) {
        accountNumber = accNo;
        balance = 0.0;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Amount Deposited Successfully!\n";
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdrawal", amount));
        cout << "Amount Withdrawn Successfully!\n";
        return true;
    }

    bool transfer(Account &receiver, double amount) {
        if (amount > balance) {
            cout << "Insufficient Balance!\n";
            return false;
        }

        balance -= amount;
        receiver.balance += amount;

        transactions.push_back(Transaction("Transfer Sent", amount));
        receiver.transactions.push_back(Transaction("Transfer Received", amount));

        cout << "Transfer Successful!\n";
        return true;
    }

    void showTransactions() {
        cout << "Transaction History:\n";
        for (int i = 0; i < transactions.size(); i++) {
            transactions[i].display();
        }
    }

    void showAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// ---------------- CUSTOMER CLASS ----------------
class Customer {
public:
    string name;
    Account account;

    Customer(string n, int accNo) : account(accNo) {
        name = n;
    }

    void displayCustomer() {
        cout << "Customer Name: " << name << endl;
        account.showAccountInfo();
    }
};

// ---------------- MAIN FUNCTION ----------------
int main() {
    Customer c1("Pulkit", 101);
    Customer c2("Rahul", 102);

    int choice;
    double amount;

    while (true) {
        cout << "\n--- BANKING SYSTEM MENU ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Show Account Info\n";
        cout << "5. Show Transactions\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount: ";
            cin >> amount;
            c1.account.deposit(amount);
            break;

        case 2:
            cout << "Enter amount: ";
            cin >> amount;
            c1.account.withdraw(amount);
            break;

        case 3:
            cout << "Enter amount: ";
            cin >> amount;
            c1.account.transfer(c2.account, amount);
            break;

        case 4:
            c1.displayCustomer();
            break;

        case 5:
            c1.account.showTransactions();
            break;

        case 6:
            cout << "Thank you for using Banking System!\n";
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }

    return 0;
}

