/*Implement books issuing components of a library. Define a class "Book" having data
members: "name" and "author" both of type string.
Derive two class "referenceBook" and "issuableBook" having following details:
genre: store genre details of the book (string)
lateReturn: store number of days of late submission of book
fine: Integer data member to store fine amount. Reference books can be issued for 1 day
and a fine of Rs. 5/day after 1 day. Issuable books can be issued for 30 days and fine of Re.
1/day after 30 days.
issueID: Unique integer data member (starts with 1 and auto incremented by 1 in every
issue)
Implement run time polymorphism to display information about 1 issuable book (late return
by 5 days) and 1 reference book (late return by 2 days) [implement appropriate methods
in the classes to perform the operations] */
#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string name;
    string author;

public:
    virtual void calculateFine(int lateReturnDays) = 0;
    virtual void displayInfo() = 0;
    virtual ~Book() {}
};

class ReferenceBook : public Book {
private:
    string genre;
    int lateReturn;
    int fine;

    int issueID;               // Individual Issue ID
    static int nextIssueID;    // Auto increment counter

public:
    ReferenceBook(string n, string a, string g, int lr) {
        name = n;
        author = a;
        genre = g;
        lateReturn = lr;
        fine = 0;
        issueID = ++nextIssueID;
    }

    void calculateFine(int lateReturnDays) override {
        if (lateReturnDays > 1)
            fine = (lateReturnDays - 1) * 5;
        else
            fine = 0;
    }

    void displayInfo() override {
        calculateFine(lateReturn);

        cout << "\nReference Book Details\n";
        cout << "Issue ID: " << issueID << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Late Return Days: " << lateReturn << endl;
        cout << "Fine: Rs. " << fine << endl;
    }
};

int ReferenceBook::nextIssueID = 0;


class IssuableBook : public Book {
private:
    string genre;
    int lateReturn;
    int fine;

    int issueID;
    static int nextIssueID;

public:
    IssuableBook(string n, string a, string g, int lr) {
        name = n;
        author = a;
        genre = g;
        lateReturn = lr;
        fine = 0;
        issueID = ++nextIssueID;
    }

    void calculateFine(int lateReturnDays) override {
        if (lateReturnDays > 30)
            fine = (lateReturnDays - 30);
        else
            fine = 0;
    }

    void displayInfo() override {
        calculateFine(lateReturn);

        cout << "\nIssuable Book Details\n";
        cout << "Issue ID: " << issueID << endl;
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Late Return Days: " << lateReturn << endl;
        cout << "Fine: Rs. " << fine << endl;
    }
};

int IssuableBook::nextIssueID = 0;

int main() {

    ReferenceBook refBook("Advanced C++", "Bjarne Stroustrup", "Programming", 2);
    IssuableBook issBook("Harry Potter", "J.K. Rowling", "Fantasy", 35);

    Book *book;

    book = &refBook;
    book->displayInfo();

    book = &issBook;
    book->displayInfo();

    return 0;
}