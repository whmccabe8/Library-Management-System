//Will McCabe
//Library Vendor Management

#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Book {
private:
    string ISBN;
    string title;
    string author;
    string genre;
    int publicationYear;
    bool isAvailable;

public:

    Book() : ISBN(""), title(""), author(""), genre(""), publicationYear(0), isAvailable(false) {}

    Book(const string& isbn, const string& bookTitle, const string& bookAuthor,
        const string& bookGenre, int year, bool available)
        : ISBN(isbn), title(bookTitle), author(bookAuthor), genre(bookGenre),
        publicationYear(year), isAvailable(available) {}


    string getISBN() const { return ISBN; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    int getPublicationYear() const { return publicationYear; }
    bool getAvailability() const { return isAvailable; }

    void setISBN(const string& isbn) { ISBN = isbn; }
    void setTitle(const string& bookTitle) { title = bookTitle; }
    void setAuthor(const string& bookAuthor) { author = bookAuthor; }
    void setGenre(const string& bookGenre) { genre = bookGenre; }
    void setPublicationYear(int year) { publicationYear = year; }
    void setAvailability(bool available) { isAvailable = available; }


    void displayBookDetails() const {
        cout << "ISBN: " << ISBN << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Genre: " << genre << endl;
        cout << "Publication Year: " << publicationYear << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    }
};


class Inventory {
private:
    vector<Book*> books;

public:
    Inventory() {}
    ~Inventory() {
        for (auto& book : books) {
            delete book;
        }
    }

    void addBook(const Book& book);
    void findBookByIsbn(const string& isbn) const;
    void removeBookByIsbn(const string& isbn);
    void isBookAvailable(const string& isbn) const;
    void listAvailableBooks() const;
    void listCheckedOutBooks() const;
    void updateBookAvailabilty(const string& isbn, bool available);
    void countTotalBooks() const;
    void countAvailableBooks() const;
};


class Library {
private:
    Inventory& inventory;
    int daysLate;

public:
    Library(Inventory& invent);

    void checkoutBook(const string& isbn);
    void returnBook(const string& isbn);
    void removeBookFromInventory(const string& isbn);
    void listAllBooks();
};

void Inventory::addBook(const Book& book) {
    books.push_back(new Book(book));
    cout << "Book added successfully!" << endl;
}

void Inventory::findBookByIsbn(const string& isbn) const {
    for (const auto& book : books) {
        if (book->getISBN() == isbn) {
            book->displayBookDetails();
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Inventory::removeBookByIsbn(const string& isbn) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if ((*it)->getISBN() == isbn) {
            delete* it;
            books.erase(it);
            cout << "Book removed successfully!" << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Inventory::isBookAvailable(const string& isbn) const {
    for (const auto& book : books) {
        if (book->getISBN() == isbn) {
            cout << (book->getAvailability() ? "Book is available." : "Book is not available.") << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Inventory::listAvailableBooks() const {
    for (const auto& book : books) {
        if (book->getAvailability()) {
            book->displayBookDetails();
        }
    }
}

void Inventory::listCheckedOutBooks() const {
    for (const auto& book : books) {
        if (!book->getAvailability()) {
            book->displayBookDetails();
        }
    }
}

void Inventory::updateBookAvailabilty(const string& isbn, bool available) {
    for (auto& book : books) {
        if (book->getISBN() == isbn) {
            book->setAvailability(available);
            cout << "Book availability updated successfully!" << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Inventory::countTotalBooks() const {
    cout << "Total number of books: " << books.size() << endl;
}

void Inventory::countAvailableBooks() const {
    int count = 0;
    for (const auto& book : books) {
        if (book->getAvailability()) {
            ++count;
        }
    }
    cout << "Number of available books: " << count << endl;
}

// Implementation of Library methods
Library::Library(Inventory& invent) : inventory(invent), daysLate(0) {}

void Library::checkoutBook(const string& isbn) {
    inventory.updateBookAvailabilty(isbn, false);
    cout << "Book checked out successfully!" << endl;
}

void Library::returnBook(const string& isbn) {
    inventory.updateBookAvailabilty(isbn, true);
    cout << "Book returned successfully!" << endl;
}

 void Library::removeBookFromInventory(const string & isbn) {
    inventory.removeBookByIsbn(isbn);
  }

void Library::listAllBooks() {
    inventory.countTotalBooks();
    inventory.listAvailableBooks();
    inventory.listCheckedOutBooks();
}

// Main function
int main() {
    Inventory inventory;
    Library library(inventory);

    int numInput1, numInput2, numInput3;
    string enterisbn;
    double enterlate;

    do {
        cout << "Main Menu" << endl;
        cout << "1. Manage Inventory" << endl;
        cout << "2. Manage Library Transactions" << endl;
        cout << "3. View Book Details" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Selection: ";
        cin >> numInput1;
        cout << endl;

        switch (numInput1) {
        case 1:
            do {
                cout << "Manage Inventory" << endl;
                cout << "1. Add Book" << endl;
                cout << "2. Remove Book" << endl;
                cout << "3. Update Book Availability" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter Your Selection: ";
                cin >> numInput2;
                cout << endl;

                switch (numInput2) {
                case 1: {
                    string isbn, title, author, genre;
                    int year;
                    bool available;
                    cout << "Enter ISBN: ";
                    cin >> isbn;
                    cout << "Enter Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Enter Author: ";
                    getline(cin, author);
                    cout << "Enter Genre: ";
                    getline(cin, genre);
                    cout << "Enter Publication Year: ";
                    cin >> year;
                    cout << "Is the book available? (1 for yes, 0 for no): ";
                    cin >> available;
                    Book newBook(isbn, title, author, genre, year, available);
                    inventory.addBook(newBook);
                    cout << endl;
                    break;
                }
                case 2:
                    cout << "Enter ISBN: ";
                    cin >> enterisbn;
                    inventory.removeBookByIsbn(enterisbn);
                    cout << endl;
                    break;
                case 3: {
                    cout << "Enter ISBN: ";
                    cin >> enterisbn;
                    bool availability;
                    cout << "Is the book available? (1 for yes, 0 for no): ";
                    cin >> availability;
                    inventory.updateBookAvailabilty(enterisbn, availability);
                    cout << endl;
                    break;
                }

                default:
                    break;
                }
            } while (numInput2 != 4);
            break;

        case 2:
            do {
                cout << "Manage Library Transactions" << endl;
                cout << "1. Checkout Book" << endl;
                cout << "2. Return Book" << endl;
                cout << "3. Exit" << endl;
                cout << "Enter Your Selection: ";
                cin >> numInput2;
                cout << endl;

                switch (numInput2) {
                case 1:
                    cout << "Enter ISBN: ";
                    cin >> enterisbn;
                    library.checkoutBook(enterisbn);
                    cout << endl;
                    break;
                case 2:
                    cout << "Enter ISBN: ";
                    cin >> enterisbn;
                    library.returnBook(enterisbn);
                    cout << endl;
                    break;
                default:
                    break;
                }
            } while (numInput2 != 3);
            break;

        case 3:
            do {
                cout << "View Book Details Options" << endl;
                cout << "1. View Details by ISBN" << endl;
                cout << "2. List All Books" << endl;
                cout << "3. Count Total Books" << endl;
                cout << "4. Count Total Available Books" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter Your Selection: ";
                cin >> numInput3;
                cout << endl;

                switch (numInput3) {
                case 1:
                    cout << "Enter ISBN: ";
                    cin >> enterisbn;
                    inventory.findBookByIsbn(enterisbn);
                    cout << endl;
                    break;
                case 2:
                    library.listAllBooks();
                    cout << endl;
                    break;
                case 3:
                    inventory.countTotalBooks();
                    cout << endl;
                    break;
                case 4:
                    inventory.countAvailableBooks();
                    cout << endl;
                    break;
                default:
                    break;
                }
            } while (numInput3 != 5);
            break;
        default:
            break;
        }
    } while (numInput1 != 4);

    return 0;
}


                    