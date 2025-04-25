#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Account {
    string name;
    int accNumber;
    float balance;

public:
    Account() : balance(0.0) {}
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNumber;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Initial Deposit: ";
        cin >> balance;
        saveToFile();
        cout << "Account Created Successfully!\n";
    }

    void saveToFile() {
        ofstream out("accounts.txt", ios::app);
        out << accNumber << " " << name << " " << balance << endl;
        out.close();
    }

    void showAccounts() {
        ifstream in("accounts.txt");
        int num;
        string accName;
        float bal;
        cout << "\n--- Account List ---\n";
        while (in >> num >> accName >> bal) {
            cout << "Account: " << num << " | Name: " << accName << " | Balance: " << bal << "\n";
        }
        in.close();
    }
};

int main() {
    Account a;
    int choice;
    do {
        cout << "\n\n=== SmartBanking Menu ===";
        cout << "\n1. Create Account";
        cout << "\n2. Show All Accounts";
        cout << "\n3. Exit";
        cout << "\nChoose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            a.createAccount();
            break;
        case 2:
            a.showAccounts();
            break;
        case 3:
            cout << "Exiting SmartBanking App. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!";
        }
    } while (choice != 3);
    return 0;
}
