#include <iostream>
using namespace std;

class Person {
public:
    int id_no;
    long mobile_no;
    char name[50];

    // Virtual functions to allow polymorphism
    virtual void infoget() {
        cout << "\nEnter the id_number:\t";
        cin >> id_no;
        cout << "\nEnter the name:\t";
        cin.ignore();
        cin.getline(name, 50);
        cout << "\nEnter the mobile number:\t";
        cin >> mobile_no;
    }

    // Virtual display function
    virtual void display() {
        cout << "\nID Number:\t" << id_no;
        cout << "\nName:\t" << name;
        cout << "\nMobile Number:\t" << mobile_no;
    }
};

class Doctor : public Person {
public:
    char specialty[50];
    int yearofexp;

    // Overriding the infoget function to get doctor-specific details
    void infoget() override {
        Person::infoget(); // Call base class function to get common info
        cout << "\nEnter the specialty:\t";
        cin.ignore();
        cin.getline(specialty, 50);
        cout << "\nEnter the year of experience:\t";
        cin >> yearofexp;
    }

    // Overriding the display function for doctor-specific details
    void display() override {
        Person::display(); // Call base class display for common info
        cout << "\nSpecialty:\t" << specialty;
        cout << "\nYears of Experience:\t" << yearofexp;
    }
};

class Nurse : public Person {
public:
    char shifttime[20];
    int patient_no;

    // Overriding the infoget function to get nurse-specific details
    void infoget() override {
        Person::infoget(); // Call base class function to get common info
        cout << "\nEnter the shifttime (morning/night):\t";
        cin.ignore();
        cin.getline(shifttime, 20);
        cout << "\nEnter the number of patients assigned:\t";
        cin >> patient_no;
    }

    // Overriding the display function for nurse-specific details
    void display() override {
        Person::display(); // Call base class display for common info
        cout << "\nShift Time:\t" << shifttime;
        cout << "\nNumber of Patients Assigned:\t" << patient_no;
    }
};

class AdminStaff : public Person {
public:
    char role[50];

    // Overriding the infoget function to get admin staff-specific details
    void infoget() override {
        Person::infoget(); // Call base class function to get common info
        cout << "\nEnter your role:\t";
        cin.ignore();
        cin.getline(role, 50);
    }

    // Overriding the display function for admin staff-specific details
    void display() override {
        Person::display(); // Call base class display for common info
        cout << "\nRole:\t" << role;
    }
};

int main() {
    Doctor doc[10];
    Nurse nurse[20];
    AdminStaff admin[20];
    int i;
    int ch;
    do {
        cout << "\nEnter your choice:\t";
        cout << "\n1. Doctor information";
        cout << "\n2. Nurse information";
        cout << "\n3. Administrative staff information";
        cout << "\n4. Display Doctor information";
        cout << "\n5. Display Nurse information";
        cout << "\n6. Display Administrative staff information";
        cout << "\n7. Exit:\t";
        cin >> ch;

        switch(ch) {
            case 1:
                int n;
                cout<<"\nEnter the number of doctor:\t";
                cin>>n;
                for(i=0;i<n;i++)
                {
                    doc[i].infoget();
                }
                 
                break;
            case 2:
                cout<<"\nEnter the number of nurse:\t";
                cin>>n;
                for(i=0;i<n;i++)
                {
                    nurse[i].infoget();
                }
                 
                break;
            case 3:
                cout<<"\nEnter the number of doctor:\t";
                cin>>n;
                for(i=0;i<n;i++)
                {
                    admin[i].infoget();
                }
                 
                break;
            case 4:
                for(i=0;i<n;i++)
                {
                   doc[i].display();
                }
                
                break;
            case 5:
                 for(i=0;i<n;i++)
                 {
                   nurse[i].display();
                 }
                
                break;
            case 6:
                for(i=0;i<n;i++)
                {
                   admin[i].display();
                }
                break;
            case 7:
                cout << "\nExiting....!";
                break;
            default:
                cout << "\nInvalid choice!";
                break;
        }
    } while (ch != 7);

    return 0;
}
