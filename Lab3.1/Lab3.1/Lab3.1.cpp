#include <iostream> //Input and output stream library for I/O use
#include <fstream> // File stream library for file I/O
#include <string> // String library for strings
#include "BooksReceived.h" // include header file for BooksReceived class

int main() {

    std::cout << "Josiah Barringer - Lab3 - Vector Assignment" << std::endl;

    //Request file name from user
    std::string filename;
    std::cout << "Shipment File Name: ";
    std::getline(std::cin, filename);

    std::ifstream file(filename); //Open the file
    if (!file.is_open()) {        // Check if file was opened
        std::cerr << "Error: Unable to open file." << std::endl; // diplay error if file doesn't open
        return 1;
    }

    // Read bookstore name, date of shipment, number of hardbound and paperback from the text file
    std::string name, date;
    int hardbound, paperback;
    if (!(std::getline(file, name) && std::getline(file, date) && (file >> hardbound) && (file >> paperback))) {
        std::cerr << "Error: Invalid file format." << std::endl;
        return 1;
    }

    // Create BooksReceived object with data from the inputted text file
    BooksReceived shipment(name, date, hardbound, paperback);

    //Read each book title from the text file and add it to the BooksReceived object
    std::string book;
    while (std::getline(file, book)) {
        if (book.empty()) continue; //Skip empty lines
        if (book.size() > 35) { // Ensure that book title doesnt exceed maximum length of 35 characters
            std::cerr << "Error: Book title exceeds maximum length." << std::endl; //Display error message if title is too long
            return 1;
        }
        shipment.addBook(book); // Add book title to the BooksReceived object
    }

    //Sort the list of books received
    shipment.sortBookList();

    //Display info about books in the shipment
    shipment.displayBooksReceivedInfo();

    return 0;
}


