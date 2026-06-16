/* A class "Master" derives information from "Account" and "Admin" classes which in turn are derived from the class "Person". Define all the four classes and write a
program to create, update and display the information contained in master objects using concept of virtual base class
Person has data members: name and code
Account has data member: pay
Admin has data member: experience
Master has derived data members: name,code,experience and pay*/
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int code;
    void getPersonData()
    {
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Code: ";
        cin >> code;
    }

    void displayPersonData()
    {
        cout << "Name : " << name << endl;
        cout << "Code : " << code << endl;
    }
};
class Account : virtual public Person
{
public:
    float pay;
    void getAccountData()
    {
        cout << "Enter Pay: ";
        cin >> pay;
    }

    void displayAccount()
    {
        cout << "Pay        : " << pay << endl;
    }
};

// Derived class Admin
class Admin : virtual public Person
{
protected:
    int experience;

public:
    void getAdmin()
    {
        cout << "Enter Experience (years): ";
        cin >> experience;
    }

    void displayAdmin()
    {
        cout << "Experience : " << experience << " years" << endl;
    }
};

// Derived class Master
class Master : public Account, public Admin
{
public:
    void create()
    {
        getPerson();
        getAccount();
        getAdmin();
    }

    void update()
    {
        cout << "\nUpdate Information\n";
        getPerson();
        getAccount();
        getAdmin();
    }

    void display()
    {
        cout << "\n----- Master Information -----\n";
        displayPerson();
        displayAccount();
        displayAdmin();
    }
};

int main()
{
    Master m;

    cout << "Enter Master Details\n";
    m.create();

    m.display();

    char ch;
    cout << "\nDo you want to update information? (y/n): ";
    cin >> ch;

    if (ch == 'y' || ch == 'Y')
    {
        m.update();
        m.display();
    }

    return 0;
}