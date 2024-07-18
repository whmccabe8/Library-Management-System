# Library Management System C++

A Library Management System coded in C++ that manages book inventory, handles library transactions such as reserving, and returning books and viewing book details. This system is control-based and has a user-friendly interface that can be easily navigated.

## Features

**Book Management:** Add, Remove, and update the availability of books.

**Library Transactions:** Checkout, Return, reserve, and renew books.

**Book Search:** Find books by ISBN and view their details.

**Inventory Statistics:** Count total number of books and availibility statistics.

## Classes

### Book: 
Represents a book in the library with the collection of ISBN, Title, Author, Genre, Publication Date, and Availibilty Status

### Library: 
Handles all library transactions such as checking out, returning, reserving, and renewing books. Also helps to process overdue books and calculate fines.

### Inventory: 
Manages the collections of books within the library. Provides the method for adding, removing, and updating books information.


## Example
```
Main Menu
1. Manage Inventory
2. Manage Library Transactions
3. View Book Details
4. Exit
Enter Your Selection: 1

Manage Inventory Options
1. Add Book
2. Remove Book
3. Update Book Availability
4. Count Total Books
5. Count Available Books
6. Exit
Enter Your Selection: 1

Enter ISBN: 978-3-16-148410-0
Enter Title: The Great Gatsby
Enter Author: F. Scott Fitzgerald
Enter Genre: Fiction
Enter Publication Year: 1925
Is the book available? (1 for yes, 0 for no): 1
Book added successfully!
```
## License

[MIT](https://choosealicense.com/licenses/mit/)
