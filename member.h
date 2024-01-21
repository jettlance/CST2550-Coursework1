#include <iostream>
#include <vector>
#include <string>

class Member : public Person {
private:
    int memberID;
    std::string name;
    std::string address;
    std::string email;
    std::vector<Book> booksLoaned;

public:
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