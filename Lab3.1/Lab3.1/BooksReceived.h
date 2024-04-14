#ifndef BOOKSRECEIVED_H
#define BOOKSRECEIVED_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

class BooksReceived {

//Private data members
private:
    std::string nameBookstore; // Bookstore name 
    std::string dateShipped; // Shipment date
    int numberHardbound; // Number hardbound books
    int numberPaperback; // Number paperback books
    std::vector<std::string> books; // Vector to store the book titles

public:
    BooksReceived(); // Zero-argument constructor
    BooksReceived(std::string name, std::string date, int hardbound, int paperback); //Four-argument constructor

    //Member functions
    void addBook(std::string book); // Add book to vector
    void sortBookList(); // Sorrt the vector of books
    int countBooksReceived() const; // Count number of books received
    void calcHardboundPercentage() const; // Calculate and display the percentage of hardbound
    void calcPaperbackPercentage() const; // Calculate and display the percentage of paperback

    //Setter and getter functions
    void setNameBookstore(std::string name);
    std::string getNameBookstore() const;
    void setDateShipped(std::string date);
    std::string getDateShipped() const;
    void setNumberHardbound(int hardbound);
    int getNumberHardbound() const;
    void setNumberPaperback(int paperback);
    int getNumberPaperback() const;

    void displayBooksReceivedInfo() const; // Display info about the book shipment
};

#endif



