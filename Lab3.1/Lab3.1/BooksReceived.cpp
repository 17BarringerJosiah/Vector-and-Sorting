#include "BooksReceived.h"

//Zero-argument constructor
BooksReceived::BooksReceived() : nameBookstore(""), dateShipped(""), numberHardbound(0), numberPaperback(0) {}

//Four-argument constructor
BooksReceived::BooksReceived(std::string name, std::string date, int hardbound, int paperback)
    : nameBookstore(name), dateShipped(date), numberHardbound(hardbound), numberPaperback(paperback) {}

//Add a book to the vector
void BooksReceived::addBook(std::string book) {
    books.push_back(book);
}

//Sort the vecotr of books
void BooksReceived::sortBookList() {
    std::sort(books.begin(), books.end());
}

//Count the number of books received
int BooksReceived::countBooksReceived() const {
    return books.size();
}

//Calculate and display te percentage of paperback books
void BooksReceived::calcHardboundPercentage() const {
    double percentage = (numberHardbound * 1.0) / (countBooksReceived() * 1.0) * 100.0;
    std::cout << "Hardbound: " << std::setprecision(1) << std::fixed << percentage << "%" << std::endl;
}

// Calculate and display the percentage of paperback books
void BooksReceived::calcPaperbackPercentage() const {
    double percentage = (numberPaperback * 1.0) / (countBooksReceived() * 1.0) * 100.0;
    std::cout << "Paperback: " << std::setprecision(1) << std::fixed << percentage << "%" << std::endl;
}

// setter and getter functions
void BooksReceived::setNameBookstore(std::string name) {
    nameBookstore = name;
}

std::string BooksReceived::getNameBookstore() const {
    return nameBookstore;
}

void BooksReceived::setDateShipped(std::string date) {
    dateShipped = date;
}

std::string BooksReceived::getDateShipped() const {
    return dateShipped;
}

void BooksReceived::setNumberHardbound(int hardbound) {
    numberHardbound = hardbound;
}

int BooksReceived::getNumberHardbound() const {
    return numberHardbound;
}

void BooksReceived::setNumberPaperback(int paperback) {
    numberPaperback = paperback;
}

int BooksReceived::getNumberPaperback() const {
    return numberPaperback;
}

//Display information about the shipment
void BooksReceived::displayBooksReceivedInfo() const {
    std::cout << "Bookstore Name: " << getNameBookstore() << std::endl;
    std::cout << "Book Shipment - Received" << std::endl;
    std::cout << "Shipment Date: " << getDateShipped() << std::endl;
    std::cout << "Books In Shipment:" << std::endl;
    std::cout << "\tHardbound: " << getNumberHardbound() << std::endl;
    std::cout << "\tPaperback: " << getNumberPaperback() << std::endl;
    std::cout << "Percent of Shipment:" << std::endl;
    calcHardboundPercentage();
    calcPaperbackPercentage();
    std::cout << "Sorted List of Books Received:" << std::endl;
    for (const auto& book : books) {
        std::cout << book << std::endl;
    }
    std::cout << "Total Books Received: " << countBooksReceived() << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
}



