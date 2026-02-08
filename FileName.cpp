#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

int accountNumbers[MAX_ACCOUNTS];
string names[MAX_ACCOUNTS];
double balances[MAX_ACCOUNTS];
int accountCount = 0;

// Function to check if account number exists
bool isAccountNumberTaken(int accNo) {
    for (int i = 0; i < accountCount; i++) {
        if (accountNumbers[i] == accNo) {
            return true;
        }
    }
    return false;
}

// Function to create a new account
void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        cout << "Bank is full! Cannot create more accounts.\n";
        return;
    }

    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    if (isAccountNumberTaken(accNo)) {
        cout << "This account number is already taken! Try a different one.\n";
        return;
    }

    accountNumbers[accountCount] = accNo;

    cout << "Enter Account Holder Name: ";
    cin.ignore(); // ignore leftover newline
    getline(cin, names[accountCount]);

    cout << "Enter Initial Balance: ";
    cin >> balances[accountCount];

    accountCount++;
    cout << "Account created successfully!\n";
}

// Function to deposit money
void deposit() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < accountCount; i++) {
        if (accountNumbers[i] == accNo) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            balances[i] += amount;
            cout << "Deposited successfully!\n";
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to withdraw money
void withdraw() {
    int accNo;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < accountCount; i++) {
        if (accountNumbers[i] == accNo) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            if (amount > balances[i]) {
                cout << "Insufficient balance!\n";
            }
            else {
                balances[i] -= amount;
                cout << "Withdrawn successfully!\n";
            }
            return;
        }
    }
    cout << "Account not found!\n";
}

// Function to display account info
void displayAccount() {
    int accNo;
    cout << "Enter Account Number: ";
    cin >> accNo;

    for (int i = 0; i < accountCount; i++) {
        if (accountNumbers[i] == accNo) {
            cout << "Account Number: " << accountNumbers[i] << endl;
            cout << "Account Holder: " << names[i] << endl;
            cout << "Balance: " << balances[i] << endl;
            return;
        }
    }
    cout << "Account not found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Bank Menu ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Display Account\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: createAccount(); break;
        case 2: deposit(); break;
        case 3: withdraw(); break;
        case 4: displayAccount(); break;
        case 5: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
