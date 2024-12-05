#include iostream
#include string
using namespace std;

class Bank {
protected
    string bankName;
    string ifscCode;
    string branch;

public
    Bank(string bName, string ifsc, string br)  bankName(bName), ifscCode(ifsc), branch(br) {}

    void displayBankDetails() const {
        cout  Bank Name   bankName  endl;
        cout  IFSC Code   ifscCode  endl;
        cout  Branch   branch  endl;
    }
};

class Manager  public Bank {
private
    string managerName;
    int managerID;

public
    Manager(string bName, string ifsc, string br, string mName, int mID) 
         Bank(bName, ifsc, br), managerName(mName), managerID(mID) {}

    void displayManagerDetails() const {
        displayBankDetails();
        cout  Manager Name   managerName  endl;
        cout  Manager ID   managerID  endl;
    }
};

class Cashier  public Bank {
private
    string cashierName;
    int cashierID;

public
    Cashier(string bName, string ifsc, string br, string cName, int cID) 
         Bank(bName, ifsc, br), cashierName(cName), cashierID(cID) {}

    void displayCashierDetails() const {
        displayBankDetails();
        cout  Cashier Name   cashierName  endl;
        cout  Cashier ID   cashierID  endl;
    }
};

int main() {
    string bankName, ifscCode, branch;
    cout  Enter Bank Name ;
    cin  bankName;
    cout  Enter IFSC Code ;
    cin  ifscCode;
    cout  Enter Branch ;
    cin  branch;

    string managerName;
    int managerID;
    cout  Enter Manager Name ;
    cin  managerName;
    cout  Enter Manager ID ;
    cin  managerID;

    string cashierName;
    int cashierID;
    cout  Enter Cashier Name ;
    cin  cashierName;
    cout  Enter Cashier ID ;
    cin  cashierID;

    Manager manager(bankName, ifscCode, branch, managerName, managerID);
    Cashier cashier(bankName, ifscCode, branch, cashierName, cashierID);

    int choice;
    
    do {
        cout  nSelect an option to display details  endl;
        cout  1. Manager Details  endl;
        cout  2. Cashier Details  endl;
        cout  3. Exit  endl;
        cout  Enter your choice ;
        cin  choice;

        switch (choice) {
            case 1
                cout  nDisplaying Manager Detailsn;
                manager.displayManagerDetails();
                break;
            case 2
                cout  nDisplaying Cashier Detailsn;
                cashier.displayCashierDetails();
                break;
            case 3
                cout  Exiting program.  endl;
                break;
            default
                cout  Invalid choice. Please try again.  endl;
        }
        cout  endl;
    } while (choice != 3);

    return 0;
}
