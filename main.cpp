#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
#include "person.h"
#include "member.h"
#include "librarian.h"
#include "book.h"

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    int dueDay, dueMonth, dueYear;  
    std::string borrowerName;  
public:
    // constructor
    // helps to store the infromation of a book
    Book(int id, const std::string name, const std::string firstName, const std::string lastName)
        : bookID(id), bookName(name), authorFirstName(firstName), authorLastName(lastName),
          borrowerName(""), dueDay(0), dueMonth(0), dueYear(0) {}

    // getter functions to represent information about a book
    int getBookID() const {
        return bookID;
    }

    std::string getBookName() const {
        return bookName;
    }

    std::string getAuthorFirstName() const {
        return authorFirstName;
    }

    std::string getAuthorLastName() const {
        return authorLastName;
    }

    std::string getBorrowerName() const {
        return borrowerName;
    }

    int getDueDay() const {
        return dueDay;
    }

    int getDueMonth() const {
        return dueMonth;
    }

    int getDueYear() const {
        return dueYear;
    }

    // setter functions to update or initialize the due date of a book
    //takes three parameters (day, month, year)
    //then assigns these values to the corresponding variables (dueDay, dueMonth, dueYear)
    void setDueDate(int day, int month, int year) {
        dueDay = day;
        dueMonth = month;
        dueYear = year;
    }
   //updating or setting the borrowers name 
    void setBorrower(const std::string borrower) {
        borrowerName = borrower;
    }

    // Member-related functions
    void borrowBook(const std::string borrower, int day, int month, int year) {
        setBorrower(borrower);
        setDueDate(day, month, year);
        std::cout << borrower << " borrowed the book '" << bookName << "'. Due date: "
                  << dueDay << "/" << dueMonth << "/" << dueYear << std::endl;
    }

    void returnBook() {
        if (!borrowerName.empty()) {
            std::cout << borrowerName << " returned the book '" << bookName << "'." << std::endl;
            setBorrower("");  
            setDueDate(0, 0, 0); 
        } else {
            std::cout << "The book '" << bookName << "' is not currently borrowed." << std::endl;
        }
    }
};

class Librarian {
private:
    int staffID;
    std::string name;
    std::string address;
    std::string email;
    int salary;
    std::vector<int> borrowedBooks;

public:
    // stores information about the librarian  
    // constructor
    Librarian(int staffID, std::string name, std::string address, std::string email, int salary)
        : staffID(staffID), name(name), address(address), email(email), salary(salary) {}

    // functions
    void addMember() {
        
        std::cout << "Member added." << std::endl;
    }

    void issueBook(int memberID, int bookID) {
        borrowedBooks.push_back(bookID);
        std::cout << "Book issued to member " << memberID << "." << std::endl;
    }

    void returnBook(int memberID, int bookID) {
        auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookID);
        if (it != borrowedBooks.end()) {
            borrowedBooks.erase(it);
            std::cout << "Book returned by member " << memberID << "." << std::endl;
        } else {
            std::cout << "Book not found in the list of borrowed books." << std::endl;
        }
    }

    void displayBorrowedBooks(int memberID) {
        std::cout << "Borrowed books by member " << memberID << ": ";
        for (int book : borrowedBooks) {
            std::cout << book << " ";
        }
        std::cout << std::endl;
    }

    void calcFine(int memberID) {

        std::cout << "Fine calculated for member " << memberID << "." << std::endl;
    }
    //a way for the librarian to display CSV file in the terminal
     std::string getCSVFileNameFromUser() {
        std::string fileName;
        std::cout << "Enter the CSV file name: ";
        std::cin >> fileName;
        return fileName;
     }

    // getter and setter functions
    int getStaffID() const {
        return staffID;
    }

    void setStaffID(int newStaffID) {
        staffID = newStaffID;
    }

    int getSalary() const {
        return salary;
    }

    void setSalary(int newSalary) {
        salary = newSalary;
    }
};

class Member : public Person {
private:
    int memberID;
    std::string name;
    std::string address;
    std::string email;
    std::vector<Book> booksLoaned;

public: //stores information about members of the library
    Member(int memberID, const std::string name, const std::string address, const std::string email)
        : Person(name, address, email), memberID(memberID) {}

    // getter functions
    int getMemberID() const {
        return memberID;
    }

    std::vector<Book> getBooksBorrowed() const {
        return booksLoaned;
    }

    // setter function
    void setBooksBorrowed(const Book book) {
        booksLoaned.push_back(book);
    }
};

class Person {
private:
    std::string name; 
    std::string address;
    std::string email;

public:
    // constructor
    Person(const std::string initialName, const std::string initialAddress, const std::string initialEmail)
        : name(initialName), address(initialAddress), email(initialEmail) {}

    // getter functions
    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return address;
    }

    std::string getEmail() const {
        return email;
    }

    // setter functions
    void setName(const std::string newName) {
        name = newName;
    }

    void setAddress(const std::string newAddress) {
        address = newAddress;
    }

    void setEmail(const std::string newEmail) {
        email = newEmail;
    }
};