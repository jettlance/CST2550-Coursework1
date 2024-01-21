#include <iostream>
#include <string>
#include <ctime>

class Date {
public:
    int day, month, year;

    Date() : day(0), month(0), year(0) {}  

    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Member {
private:
    std::string memberName;

public: 
    Member(const std::string& name) : memberName(name) {}

    std::string getMemberName() const {
        return memberName;
    }
};

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    Date dueDate;
    Member* borrower;

public:
    // Constructor
    Book(int id, const std::string& name, const std::string& firstName, const std::string& lastName)
        : bookID(id), bookName(name), authorFirstName(firstName), authorLastName(lastName), borrower(nullptr) {}

    // Getter functions
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

    Date getDueDate() const {
        return dueDate;
    }

    // Setter function
    void setDueDate(const Date& newDueDate) {
        dueDate = newDueDate;
    }

    // Member-related functions
    void borrowBook(Member* borrower, const Date& dueDate) {
        this->borrower = borrower;
        this->dueDate = dueDate;
        std::cout << borrower->getMemberName() << " borrowed the book '" << bookName << "'. Due date: "
                  << dueDate.day << "/" << dueDate.month << "/" << dueDate.year << std::endl;
    }

    void returnBook() {
        if (borrower != nullptr) {
            std::cout << borrower->getMemberName() << " returned the book '" << bookName << "'." << std::endl;
            borrower = nullptr;
        } else {
            std::cout << "The book '" << bookName << "' is not currently borrowed." << std::endl;
        }
    }
};