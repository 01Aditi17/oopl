#include <iostream>
#include <string>
using namespace std;

class bankdetails {
public:
    string name;
    int account_no;
    int balance;

    void accept() {
        cout << "\nEnter the name of depositor:\t";
        cin >> name;
        cout << "\nEnter the account number:\t";
        cin >> account_no;
        cout << "\nEnter the current bank balance:\t";
        cin >> balance;
    }

    void display() {
        cout << "\n" << name << "\t\t" << balance;
    }

    static void withdraw(int n, int i, bankdetails obj[]) {
        string depositor_name;
        cout << "\nEnter the name of depositor to withdraw amount:\t";
        cin >> depositor_name;
        for (i = 0; i < n; i++) {
            if (obj[i].name == depositor_name) {
                int withdraw_amount;
                cout << "\nEnter the withdraw amount:\t";
                cin >> withdraw_amount;
                if (obj[i].balance >= withdraw_amount) {
                    obj[i].balance -= withdraw_amount;
                    cout << "\nSuccessfully withdrawn " << withdraw_amount << " amount from the account. Current balance: " << obj[i].balance;
                } else {
                    cout << "\nInsufficient balance.";
                }
                return; // Exit the loop after processing the withdrawal
            }
        }
        cout << "\nInvalid depositor name.";
    }

    static void deposite(int n, int i, bankdetails obj[]){
        string depositor_name;
        cout << "\nEnter the name of depositor to deposite amount:\t";
        cin >> depositor_name;
        for (i = 0; i < n; i++) {
            if (obj[i].name == depositor_name) {
                float deposite_amount;
                cout << "\nEnter the deposite amount:\t";
                cin >> deposite_amount;

                    obj[i].balance += deposite_amount;
                    cout << "\nSuccessfully deposite " << deposite_amount << " amount from the account. Current balance: " << obj[i].balance;
            }
        }
        cout << "\nInvalid depositor name.";
	}
};

int main() {
    bankdetails obj[10];
    int i, n, choice;
    do {
        cout << "\n1. Store Data";
        cout << "\n2. Display Data";
        cout << "\n3. Withdraw Amount";
        cout << "\n4. Deposit Amount";
        cout << "\n5. Exit";
         cout <<"\nEnter your choice from above:\t";
        cin >> choice;

        switch (choice) {
            case 1:
                 cout << "Enter the number of data you want to enter:\t";
                 cin >> n;
                 for (i = 0; i < n; i++) {
                      obj[i].accept();
                    }
                break;
            case 2:
                cout << "\nName\t\tBalance";
                for (i = 0; i < n; i++) {
                    obj[i].display();
                }
                break;
            case 3:
                bankdetails::withdraw(n, i, obj);
                break;
            case 4:
                bankdetails::deposite(n, i, obj);
                break;
            case 5:
                cout << "\nExiting...";
                break;
            default:
                cout << "\nInvalid choice";
        }
    } while (choice != 5);

     return 0;
}